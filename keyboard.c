/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:00:33 by salee2            #+#    #+#             */
/*   Updated: 2022/09/26 11:00:34 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    exit_fractol(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}

t_plane	get_moved_plane(t_plane plane, int keycdoe)
{
    const double power = 0.2;
    const int dir = keycdoe - 124;
    const int di[4] = {0, 0, 1, -1};
    const int dr[4] = {-1, 1, 0, 0};

    double imag_size = fabs(plane.imag_max - plane.imag_min);
    double imag_max = plane.imag_max + di[dir]*imag_size * power;
    double imag_min = plane.imag_min + di[dir]*imag_size * power;

    double real_size = fabs(plane.real_max - plane.real_min);
    double real_max = plane.real_max + dr[dir]* real_size * power;
    double real_min = plane.real_min + dr[dir]* real_size * power;

    return (t_plane){imag_max, imag_min, real_min, real_max};
}


void    move_frame(int keycode, t_vars *vars)
{
    get_moved_plane(vars->plane, keycode);
    mlx_clear_window(vars->mlx, vars->win);
    vars->plane = get_moved_plane(vars->plane, keycode);
    get_fractal_image(vars);
    print_plane(&vars->plane);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	key_hook(int keycode, t_vars *vars)
{
    if (keycode == KEY_ESC)
        exit_fractol(vars);
    else if(124 <= keycode && keycode <= 126)
    {
        move_frame(keycode, vars);
    }

    return (0);
}


