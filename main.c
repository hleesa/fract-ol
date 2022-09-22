/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:20:34 by salee2            #+#    #+#             */
/*   Updated: 2022/09/13 19:55:37 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("button:%d, x:%d, y:%d\n", button, x, y);
	mlx_clear_window(vars->mlx, vars->win);
	vars->plane = get_next_plane(vars->plane, x, y, button);
//	get_mandelbrot_image(vars);
	get_julia_image(vars);
	print_plane(vars->plane);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	main()
{
	t_vars vars;

	init_vars(&vars);
	print_plane(vars.plane);
//	get_mandelbrot_image(&vars);
	get_julia_image(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);

	return (0);

}