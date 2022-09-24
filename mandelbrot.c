/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:29:51 by salee2            #+#    #+#             */
/*   Updated: 2022/09/22 13:29:52 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

/*
void	get_mandelbrot_image(t_vars *vars)
{
	for (int dy = 0; dy < Y_MAX; ++dy)
	{
		for (int dx = 0; dx < X_MAX; ++dx)
		{
			t_complex c = cartesian_to_complex(dx, dy, vars->plane);
			t_complex z = (t_complex) {0.0, 0.0};
			double x2 =0;
			double y2 = 0;
			double w = 0;
			int i = -1;
			while (x2+y2 <= MANDELBROT_ESCAPE_RADIUS && i < ITER_MAX)
			{
//				double xtemp = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = x2 - y2 + c.real;
				y2 = z.imag * z.imag;
				x2 = z.real * z.real;
				++i;
			}
			double mag = ((double)i / (double)ITER_MAX) * 255;
			int hue = 255 * mag;
			int satu = 255;
			int value = 255;
			if(i != ITER_MAX)
				value = 0;
			int color = create_trgb(0, hue, hue, value);
			my_mlx_pixel_put(&vars->img, dx, dy, color);
		}
	}
	printf("depth:%d\n", vars->depth);

}
*/

void	get_mandelbrot_image(t_vars *vars)
{
	for (int dy = 0; dy < Y_MAX; ++dy)
	{
		for (int dx = 0; dx < X_MAX; ++dx)
		{
			t_complex c = cartesian_to_complex(dx, dy, vars->plane);
			t_complex z = (t_complex) {0.0, 0.0};
			int i = -1;
			while (complex_size(z) <= MANDELBROT_ESCAPE_RADIUS && i < ITER_MAX)
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