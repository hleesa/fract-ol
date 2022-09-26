/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:34:50 by salee2            #+#    #+#             */
/*   Updated: 2022/09/26 14:34:51 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_fractal_image(t_vars *vars)
{
	int	dy;
	int	dx;
	int	color;

	dy = -1;
	while (++dy < Y_MAX)
	{
		dx = -1;
		while (++dx < X_MAX)
		{
			color = create_color(vars->fractal.color_type, \
			vars->frt_ptr(vars, dx, dy));
			my_mlx_pixel_put(&vars->img, dx, Y_MAX - dy, color);
		}
	}
	return ;
}
