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


void print_plane(t_plane plane)
{
	printf("im max:%f, ", plane.imag_max);
	printf("im min:%f, ", plane.imag_min);
	printf("re min:%f, ", plane.real_min);
	printf("re max:%f\n", plane.real_max);

}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("button:%d, x:%d, y:%d\n", button, x, y);
	if (y < 0 || button < 4)
		return (0);
	mlx_clear_window(vars->mlx, vars->win);
	t_plane next_plane = get_next_plane(vars->plane, x, y, button);
	for (int dy = 0; dy < Y_MAX; ++dy)
	{
		for (int dx = 0; dx < X_MAX; ++dx)
		{
			t_complex z = {0.0, 0.0};
			t_complex c = cartesian_to_complex2(dx, dy, button, next_plane);
			int i = -1;
			while (complex_size(z) <= ESCAPE_RADIUS && i < ITER_MAX)
			{
				double xtemp = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = xtemp;
				++i;
			}
			int color = (double)i / (double)ITER_MAX * (double)0x00ffffff;
			my_mlx_pixel_put(&vars->img, dx, dy, color);
		}
	}
	vars->plane = next_plane;
	print_plane(vars->plane);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	vars->mul *= vars->mul;
	return (0);
}

int	main()
{

	t_vars vars;
	vars.mul = 1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, X_MAX, Y_MAX, "fract-ol");
	vars.img.img = mlx_new_image(vars.mlx, X_MAX, Y_MAX);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
								 &vars.img.endian);
	vars.plane =(t_plane){2, -2, -2, 2};
	t_mouse_data mouse_data;
	print_plane(vars.plane);
	for (int dy = 0; dy < Y_MAX; ++dy)
	{
		for (int dx = 0; dx < X_MAX; ++dx)
		{
//			t_complex c = cartesian_to_complex(dx -x +X_MAX/2, dy -x+Y_MAX/2);
			t_complex c = cartesian_to_complex2(dx, dy, 0, vars.plane);
			t_complex z = (t_complex) {0.0, 0.0};
			int i = -1;
			while (complex_size(z) <= ESCAPE_RADIUS && i < ITER_MAX)
			{
				double xtemp = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = xtemp;
				++i;
			}
			int color = (double)i / (double)ITER_MAX * (double)0x00ffffff;
			my_mlx_pixel_put(vars.img.img, dx, dy, color);
		}
	}

	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);

	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);

	return (0);

}