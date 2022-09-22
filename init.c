/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:18:26 by salee2            #+#    #+#             */
/*   Updated: 2022/09/22 13:18:27 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, X_MAX, Y_MAX, "fract-ol");
	vars->img.img = mlx_new_image(vars->mlx, X_MAX, Y_MAX);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
									  &vars->img.endian);
//	vars->plane =(t_plane){2, -2, -2.5, 1.5};
	vars->plane =(t_plane){2, -2, -2, 2};
	vars->depth = 0;
}
