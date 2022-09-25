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

//void	get_mandelbrot_image(t_vars *vars)
//{
//	for (int dy = 0; dy < Y_MAX; ++dy)
//	{
//		for (int dx = 0; dx < X_MAX; ++dx)
//		{
//            t_complex z = (t_complex) {0.0, 0.0};
//            t_complex c = cartesian_to_complex(dx, dy, vars->plane);
//			int i = -1;
//			while (complex_size(z) <= MANDELBROT_ESCAPE_RADIUS && i < ITER_MAX)
//			{
//				double xtemp = z.real * z.real - z.imag * z.imag + c.real;
//				z.imag = 2 * z.real * z.imag + c.imag;
//				z.real = xtemp;
//				++i;
//			}
//			if(i != ITER_MAX)
//				i = i + 1 - log(log2(complex_size(z)));
//			double t = (double)i / (double)ITER_MAX;
//			int color = create_color(t);
//			my_mlx_pixel_put(&vars->img, dx, dy, color);
//		}
//    }
//}

//int     get_mandelbrot_element(t_vars *vars, int y, int x)
//{
//    int i;
//    t_complex z = vars->fractal.z;
//    t_complex c = cartesian_to_complex(x, y, vars->plane);
//    const double escape_radius = 4;
//
//    i = -1;
//    while (complex_size(z) <= escape_radius && i < ITER_MAX)
//    {
//        double xtemp = z.real * z.real - z.imag * z.imag + c.real;
//        z.imag = 2 * z.real * z.imag + c.imag;
//        z.real = xtemp;
//        ++i;
//    }
//    if(i != ITER_MAX)
//        i = i + 1 - log(log2(complex_size(z)));
//    return (i);
//}

int     get_mandelbrot_element(t_vars *vars, int y, int x)
{
    int i;
    t_complex z;
    t_complex c;
    t_complex sq;
    const double escape_radius = 4;

    z = vars->fractal.z;
    c = cartesian_to_complex(x, y, vars->plane);
    sq = (t_complex) {0.0, 0.0};
    i = -1;
    while (sq.real + sq.imag <= escape_radius && i < ITER_MAX)
    {
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = sq.real - sq.imag + c.real;
        sq.real = z.real * z.real;
        sq.imag = z.imag * z.imag;
        ++i;
    }
    if(i != ITER_MAX)
        i = i + 1 - log(log2(complex_size(z)));
    return (i);
}

//void	get_mandelbrot_image(t_vars *vars)
//{
//    int i;
//    int dy;
//    int dx;
//
//    vars->frt_ptr = get_mandelbrot_element;
//    dy = -1;
//    while(++dy < Y_MAX)
//    {
//        dx = -1;
//        while(++dx < X_MAX)
//        {
//            i = vars->frt_ptr(vars, dy, dx);
//            double t = (double)i / (double)ITER_MAX;
//            int color = create_color(t);
//            my_mlx_pixel_put(&vars->img, dx, dy, color);
//        }
//    }
//}

void	get_fractal_image(t_vars *vars)
{
    int i;
    int dy;
    int dx;

    dy = -1;
    while(++dy < Y_MAX)
    {
        dx = -1;
        while(++dx < X_MAX)
        {
            i = vars->frt_ptr(vars, dy, dx);
            double t = (double)i / (double)ITER_MAX;
            int color = create_color(t);
            my_mlx_pixel_put(&vars->img, dx, dy, color);
        }
    }
}