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


t_complex	complex_mul(t_complex lhs, t_complex rhs)
{
	const double real = lhs.real * rhs.real - lhs.imag * rhs.imag;
	const double imag = lhs.real * rhs.imag + lhs.imag * rhs.real;
	return ((t_complex){real, imag});
}

t_complex	complex_sum(t_complex lhs, t_complex rhs, double sign)
{
	const double real = lhs.real + sign * rhs.real;
	const double imag = lhs.imag + sign * rhs.imag;
	return ((t_complex){real, imag});
}

double	complex_size(t_complex comp)
{
	return (comp.real * comp.real + comp.imag * comp.imag);
}

t_complex	cartesian_to_complex(int x, int y)
{
	const double imag = (double)y* (double)IM_SIZE / (double)YMAX - (double)IM_SIZE / 2.0;
	const double real = (double)x* (double)RE_SIZE / (double )XMAX - (double)RE_SIZE / 2.0;
	return ((t_complex){real, imag});
}

//int	mouse_hook(int button, int x, int y, t_mouse_data *mouse_data)
//{
//	*mouse_data = (t_mouse_data){button,x,y};
//	printf("button:%d, x:%d, y:%d\n", mouse_data->button, mouse_data->x,
//		   mouse_data->y);
//
//	for(int dy=0; dy<YMAX;++dy)
//	{
//		for(int dx=0; dx<XMAX; ++dx)
//		{
//			t_complex c = cartesian_to_complex(dx, dy);
//			t_complex z = (t_complex) {0.0, 0.0};
//			int i = -1;
//			while (complex_size(z) <= 4 && i < 1000)
//			{
//				double xtemp = z.real*z.real -z.imag*z.imag + c.real;
//				z.imag = 2 * z.real * z.imag + c.imag;
//				z.real = xtemp;
//				++i;
//			}
//			if (i == 1000)
//				mlx_pixel_put(mlx_ptr, win_ptr, dx, dy, 0xffffff);
//		}
//	}
//
//	return (0);
//}

/*
int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("button:%d, x:%d, y:%d\n",button,x,y);
	mlx_clear_window(vars->mlx, vars->win);
	for(int dy=0; dy<YMAX;++dy)
	{
		for(int dx=0; dx<XMAX; ++dx)
		{
			t_complex c = cartesian_to_complex(dx -x +XMAX/2, dy-y+YMAX/2);
			c.imag *= vars->mul;
			c.real *= vars->mul;

			t_complex z = (t_complex) {0.0, 0.0};
			int i = -1;
			while (complex_size(z) <= 4 && i < 1000)
			{
				double xtemp = z.real*z.real -z.imag*z.imag + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = xtemp;
				++i;
			}
			if (i == 1000)
				mlx_pixel_put(vars->mlx, vars->win, dx, dy, 0xffffff);
		}
	}
	vars->mul *= vars->mul;
	return (0);
}

int	main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, XMAX, YMAX, "fract-ol");
	for(int dy=0; dy<YMAX;++dy)
	{
		for(int dx=0; dx<XMAX; ++dx)
		{
			t_complex c = cartesian_to_complex(dx, dy);
			t_complex z = (t_complex) {0.0, 0.0};
			int i = -1;
			while (complex_size(z) <= 4 && i < 1000)
			{
				double xtemp = z.real*z.real -z.imag*z.imag + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = xtemp;
				++i;
			}
			if (i == 1000)
				mlx_pixel_put(mlx_ptr, win_ptr, dx, dy, 0xffffff);
		}
	}

	t_vars vars = (t_vars) {mlx_ptr, win_ptr, 0.95};
	t_mouse_data mouse_data;
	mlx_mouse_hook(win_ptr, mouse_hook, &vars);
	mlx_loop(mlx_ptr);

	return (0);

}
*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
