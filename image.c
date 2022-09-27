/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:34:26 by salee2            #+#    #+#             */
/*   Updated: 2022/09/27 14:18:24 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

void	init_mlx_n_img(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, X_MAX, Y_MAX, "fractol");
	vars->img.img = mlx_new_image(vars->mlx, X_MAX, Y_MAX);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
	&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	return ;
}
