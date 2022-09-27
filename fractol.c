/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:34:50 by salee2            #+#    #+#             */
/*   Updated: 2022/09/26 14:34:51 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_z_c(t_vars *vars, t_complex *z, t_complex *c, t_cartesian coord)
{
	if (vars->fractal.name == JULIA)
	{
		*z = cartesian_to_complex(coord.x, coord.y, &vars->fractal.plane);
		*c = vars->fractal.c;
	}
	else
	{
		*z = vars->fractal.z;
		*c = cartesian_to_complex(coord.x, coord.y, &vars->fractal.plane);
	}
	return ;
}

int	get_fractal_element(t_vars *vars, int x, int y, int sign)
{
	int				i;
	t_complex		z;
	t_complex		c;
	t_complex		sq;

	set_z_c(vars, &z, &c, (t_cartesian){x, y});
	sq = (t_complex){z.real * z.real, z.imag * z.imag};
	i = -1;
	while (sq.real + sq.imag <= ESCAPE_RADIUS && ++i < ITER_END)
	{
		z.imag = 2 * sign * z.real * z.imag + c.imag;
		z.real = sq.real - sq.imag + c.real;
		sq.real = z.real * z.real;
		sq.imag = z.imag * z.imag;
	}
	if (i != 0 && i != ITER_END)
		i = i + 1 - log(log2(sq.real + sq.imag));
	return (i);
}

int	get_element_sign(t_fractal *fractal)
{
	if (fractal->name == TRICORN)
		return (-1);
	return (1);
}

void	get_fractal_image(t_vars *vars)
{
	int			dy;
	int			dx;
	int			color;
	const int	sign = get_element_sign(&vars->fractal);

	dy = -1;
	while (++dy < Y_END)
	{
		dx = -1;
		while (++dx < X_END)
		{
			color = create_color(vars->fractal.color_type, \
			get_fractal_element(vars, dx, dy, sign));
			my_mlx_pixel_put(&vars->img, dx, Y_END - dy, color);
		}
	}
	return ;
}
