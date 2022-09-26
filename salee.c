/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salee2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:10:12 by salee2            #+#    #+#             */
/*   Updated: 2022/09/26 15:10:13 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_salee_element(t_vars *vars, int x, int y)
{
	int				i;
	t_complex		z;
	t_complex		c;
	t_complex		sq;
	const double	escape_radius = 4;

	z = vars->fractal.z;
	c = cartesian_to_complex(x, y, vars->fractal.scope);
	sq = (t_complex){z.real * z.real, z.imag * z.imag};
	i = -1;
	while (sq.real + sq.imag <= escape_radius && ++i < ITER_MAX)
	{
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = sq.real - sq.imag + c.real;
		sq.real = z.real * z.real;
		sq.imag = z.imag * z.imag;
	}
	if (i != 0 && i != ITER_MAX)
		i = i + 1 - log(log2(complex_size(z)));
	return (i);
}
