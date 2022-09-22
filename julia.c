/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:36:51 by salee2            #+#    #+#             */
/*   Updated: 2022/09/22 17:36:53 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	get_julia_image(t_vars *vars)
{
	for (int dy = 0; dy < Y_MAX; ++dy)
	{
		for (int dx = 0; dx < X_MAX; ++dx)
		{
			t_complex z = cartesian_to_complex(dx, dy, vars->plane);
			t_complex c = (t_complex) {0.285, 0.01};
			int i = -1;
			while (complex_size(z) <= JULIA_ESCAPE_RADIUS&& i < ITER_MAX)
			{
				double xtemp = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = xtemp;
				++i;
			}
			if(i != ITER_MAX)
				i = i + 1 - log(log2(complex_size(z)));
			double t = (double)i / (double)ITER_MAX;
			int color = create_color(t);
			my_mlx_pixel_put(&vars->img, dx, dy, color);
		}
	}
}

