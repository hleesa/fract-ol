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

void	exit_fractol(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

t_plane	get_moved_plane(t_plane plane, int keycdoe)
{
	t_plane		ret;
	t_move_info	info;
	const int	di[4] = {0, 0, -1, 1};
	const int	dr[4] = {-1, 1, 0, 0};

	info.power = 0.15;
	info.dir = keycdoe - 123;
	info.size.imag = fabs(plane.imag_max - plane.imag_min);
	info.size.real = fabs(plane.real_max - plane.real_min);
	ret.imag_max = plane.imag_max + di[info.dir] * info.size.imag * info.power;
	ret.imag_min = plane.imag_min + di[info.dir] * info.size.imag * info.power;
	ret.real_max = plane.real_max + dr[info.dir] * info.size.real * info.power;
	ret.real_min = plane.real_min + dr[info.dir] * info.size.real * info.power;
	return (ret);
}

void	move_frame(int keycode, t_vars *vars)
{
	get_moved_plane(vars->fractal.plane, keycode);
	mlx_clear_window(vars->mlx, vars->win);
	vars->fractal.plane = get_moved_plane(vars->fractal.plane, keycode);
	get_fractal_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit_fractol(vars);
	else if (123 <= keycode && keycode <= 126)
		move_frame(keycode, vars);
	return (0);
}
