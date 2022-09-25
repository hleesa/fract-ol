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
	if(button ==SCROLL_UP)
		++vars->depth;
	else if (button == SCROLL_DOWN)
		--vars->depth;
	printf("button:%d, x:%d, y:%d, dep:%d\n", button, x, y, vars->depth);
	mlx_clear_window(vars->mlx, vars->win);
	vars->plane = get_next_plane(vars->plane, x, y, button);
    get_fractal_image(vars);
//	get_mandelbrot_image(vars);
//	get_julia_image(vars);
	print_plane(&vars->plane);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}

int	main(int argc, char *argv[])
{
	t_vars vars;

	init_vars(&vars);
    init_fractal_arg(argc,&argv, &vars.fractal);
    init_fractal_scope(&vars.fractal);
	print_plane(&vars.fractal.scope);
    init_fractal_ptr(&vars);

    get_fractal_image(&vars);
//	get_mandelbrot_image(&vars);
//	get_julia_image(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);

	return (0);

}