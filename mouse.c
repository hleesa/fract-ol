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

int	red_cross(void)
{
	exit(0);
}

void	zoom_in_out(int button, int x, int y, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	vars->fractal.plane = get_zoomed_plane(&vars->fractal.plane, x, Y_END - y, \
	button);
	get_fractal_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return ;
}

void	change_color(t_vars *vars)
{
	vars->fractal.color_type = (vars->fractal.color_type + 1) % COLOR_TYPES;
	mlx_clear_window(vars->mlx, vars->win);
	get_fractal_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return ;
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == RIGHT_CLICK)
		change_color(vars);
	else if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom_in_out(button, x, y, vars);
	return (0);
}
