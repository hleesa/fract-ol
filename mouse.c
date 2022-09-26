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

void	zoom_in_out(int button, int x, int y, t_vars *vars)
{
	if (button == SCROLL_UP)
		++vars->fractal.depth;
	else if (button == SCROLL_DOWN)
		--vars->fractal.depth;
	printf("button:%d, x:%d, y:%d, dep:%d\n", button, x, y, vars->fractal.depth);
	mlx_clear_window(vars->mlx, vars->win);
	vars->fractal.plane = get_next_plane(vars->fractal.plane, x, Y_MAX - y, \
	button);
	get_fractal_image(vars);
	print_plane(&vars->fractal.plane);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	change_color(t_vars *vars)
{
	vars->fractal.color_type = (vars->fractal.color_type + 1) % COLOR_TYPES;
	mlx_clear_window(vars->mlx, vars->win);
	get_fractal_image(vars);
	print_plane(&vars->fractal.plane);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == RIGHT_CLICK)
		change_color(vars);
	else if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom_in_out(button, x, y, vars);
	return (0);
}
