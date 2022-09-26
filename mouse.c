/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:57:51 by salee2            #+#    #+#             */
/*   Updated: 2022/09/26 10:57:52 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    zoom_in_out(int button, int x, int y, t_vars *vars)
{
    printf("button:%d, x:%d, y:%d, dep:%d\n", button, x, y, vars->depth);
    mlx_clear_window(vars->mlx, vars->win);
    vars->plane = get_next_plane(vars->plane, x, y, button);
    get_fractal_image(vars);
    print_plane(&vars->plane);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void    change_color(t_vars *vars)
{
    vars->fractal.color_type = (vars->fractal.color_type + 1) % COLOR_TYPES;
    mlx_clear_window(vars->mlx, vars->win);
    get_fractal_image(vars);
    print_plane(&vars->plane);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
    if(button == RIGHT_CLICK)
    {
        change_color(vars);
        return (0);
    }
    if(button ==SCROLL_UP)
        ++vars->depth;
    else if (button == SCROLL_DOWN)
        --vars->depth;
    zoom_in_out(button, x, y, vars);
    return (0);
}
