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

#include "fractol.h"

int     get_mandelbrot_element(t_vars *vars, int y, int x)
{
    int i;
    t_complex z;
    t_complex c;
    t_complex sq;
    const double escape_radius = 4;

    z = vars->fractal.z;
    c = cartesian_to_complex(x, y, vars->plane);
    sq = (t_complex){z.real * z.real, z.imag * z.imag};
    i = -1;
    while (sq.real + sq.imag <= escape_radius && i < ITER_MAX)
    {
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = sq.real - sq.imag + c.real;
        sq.real = z.real * z.real;
        sq.imag = z.imag * z.imag;
        ++i;
    }
    if(i != 0 && i != ITER_MAX)
        i = i + 1 - log(log2(complex_size(z)));
    return (i);
}

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
            int color = create_color(vars->fractal.color_type, i);
            my_mlx_pixel_put(&vars->img, dx, dy, color);
        }
    }
}