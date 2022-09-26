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

void    init_fractal_ptr(t_vars *vars)
{
    if (vars->fractal.name == MANDELBROT)
        vars->frt_ptr = get_mandelbrot_element;
    else if (vars->fractal.name == JULIA)
        vars->frt_ptr = get_julia_element;
    else if (vars->fractal.name == SALEE)
        vars->frt_ptr = get_salee_element;
    return ;
}

void    init_fractal_scope(t_fractal *fractal)
{
    const t_plane name_to_scope[FRACTAL_TYPES] = {
            {2, -2, -2.5, 1.5},{2, -2, -2, 2}, {2, -2, -2, 2}
    };
    fractal->scope = name_to_scope[fractal->name];
    return ;
}

void	init_fractal_arg(int argc, char ***argv, t_fractal *fractal)
{
	int i;
	const char* name[FRACTAL_TYPES] = {"mandelbrot", "julia","salee"};

	if(argc == 1)
		return (exit(intro_fractal_type()));
    i = -1;
	while(++i < FRACTAL_TYPES)
	{
		if(ft_strcmp((*argv)[1], name[i]) == 0)
        {
            fractal->name = i;
            break;
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

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, X_MAX, Y_MAX, "fractol");
	vars->img.img = mlx_new_image(vars->mlx, X_MAX, Y_MAX);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
									  &vars->img.endian);
	vars->plane =(t_plane){2, -2, -2.5, 1.5};
//	vars->plane =(t_plane){2, -2, -2, 2};
	vars->depth = 0;
}

