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

void	init_fractal_arg(int argc, char ***argv, t_fractal *fractal)
{
	int i;
	t_bool	is_error;
	const char* name[FRACTAL_TYPES] = {"mandelbrot", "julia","salee"};

	if(argc == 1)
		return (exit(intro_fractal_type()));
	i = 0;
	while(++i < FRACTAL_TYPES)
	{
		if(ft_strcmp(argv[1], name[i] == 0))
			fractal->name = name[i];
	}
//	if(argc >= 2)
//		ft_atof(argv[2])



}



void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, X_MAX, Y_MAX, "fract-ol");
	vars->img.img = mlx_new_image(vars->mlx, X_MAX, Y_MAX);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
									  &vars->img.endian);
	vars->plane =(t_plane){2, -2, -2.5, 1.5};
//	vars->plane =(t_plane){2, -2, -2, 2};
	vars->depth = 0;
}

