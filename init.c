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

#include "fractol.h"

void	init_fractal_arg(int argc, char ***argv, t_fractal *fractal)
{
	int			i;
	const char	*name[FRACTAL_TYPES] = {"mandelbrot", "julia", "tricorn"};

	if (argc == 1)
		return (exit(intro_fractal_type()));
	i = -1;
	while (++i < FRACTAL_TYPES)
	{
		if (ft_strcmp((*argv)[1], name[i]) == 0)
		{
			fractal->name = i;
			break ;
		}
	}
	if (i == FRACTAL_TYPES)
		return (exit(intro_fractal_type()));
	if (fractal->name != JULIA)
		return ;
	if (argc < 4)
		return (exit(intro_fractal_type()));
	fractal->c.real = ft_atof((*argv)[2]);
	fractal->c.imag = ft_atof((*argv)[3]);
	return ;
}

void	init_fractal_plane(t_fractal *fractal)
{
	const t_plane	name_to_plane[FRACTAL_TYPES] = {{2, -2, -2.5, 1.5}, \
	{2, -2, -2, 2}, {2.5, -2.5, -2.5, 2.5}};

	fractal->plane = name_to_plane[fractal->name];
	return ;
}

void	init_fractal(int argc, char ***argv, t_vars *vars)
{
	vars->fractal.color_type = 3;
	init_fractal_arg(argc, argv, &vars->fractal);
	init_fractal_plane(&vars->fractal);
	return ;
}

void	init(int argc, char ***argv, t_vars *vars)
{
	init_mlx_n_img(vars);
	init_fractal(argc, argv, vars);
	get_fractal_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return ;
}
