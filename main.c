/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:20:34 by salee2            #+#    #+#             */
/*   Updated: 2022/09/13 19:55:37 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("button:%d, x:%d, y:%d\n", button, x, y);

	for (int dy = 0; dy < Y_MAX; ++dy)
	{
		for (int dx = 0; dx < X_MAX; ++dx)
		{
			t_complex c = cartesian_to_complex(dx -x +X_MAX/2, dy -x+Y_MAX/2);
			c.imag *= vars->mul;
			c.real *= vars->mul;

			t_complex z = (t_complex) {0.0, 0.0};
			int i = -1;
			while (complex_size(z) <= ESCAPE_RADIUS && i < ITER_MAX)
			{
				double xtemp = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = xtemp;
				++i;
			}
			if (i == ITER_MAX)
			{
				int color = (double)i * (double)0xffffff / (double)ITER_MAX;
				my_mlx_pixel_put(&vars->img, dx, dy, color);
			}
		}
	}

	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	vars->mul *= vars->mul;
	return (0);
}

int	main()
{

	t_vars vars;
	vars.mul = 0.95;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, X_MAX, Y_MAX, "fract-ol");
	vars.img.img = mlx_new_image(vars.mlx, X_MAX, Y_MAX);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								 &vars.img.endian);
	t_mouse_data mouse_data;
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);

	return (0);

}