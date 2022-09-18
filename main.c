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

void ft_putchar(char c)
{
	write(1, &c, 1);
}


int deal_key(int key, void *mlx_ptr, void *win_ptr)
{
	/*
	t_complex com;

	com.real = 0.0;
	com.imag = 0.0;

	for(double y0=-3.0; y0<3.0; y0 += 0.01)
	{
		for(double x0=-3.0; x0<3.0; x0 += 0.01)
		{
			int i = 0;
			double y = 0;
			double x = 0;
			while(y * y + x *x <= 2*2 && ++i <1000 )
			{
				double xtemp = x * x - y * y + x0;
				y = 2 * x * y + y0;
				x = xtemp;
			}
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x000fff);
		}
	}
	 */
//	for(int y=0; y<500;++y)
//	{
//		for(int x=0; x<500; ++x)
//		{
//			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x000fff);
//		}
//	}
//	mlx_pixel_put(mlx_ptr, win_ptr, 0,0 , 0x000fff);


	return 0;
}

//
//int deal_key(int key, void *param)
//{
//	ft_putchar('x');
//	return 0;
//}

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

int	main()
{
	void *mlx_ptr;
	void *win_ptr;
/*
	t_complex test = {1, 2};
	t_complex test2= {2, 3};

	t_complex mul = complex_mul(test, test2);
	printf("mul:%f %f\n", mul.real, mul.imag);
	t_complex sum = complex_sum(test, test2, -1);
	printf("mul:%f %f\n", sum.real, sum.imag);
*/

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, XMAX, YMAX, "fract-ol");
	for(int y=0; y<YMAX;++y)
	{
		for(int x=0; x<XMAX; ++x)
		{
			t_complex c = cartesian_to_complex(x, y);
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
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
		}
	}
	mlx_key_hook(win_ptr, deal_key,(void *)0);
//	mlx_key_hook(win_ptr, deal_key( 0, mlx_ptr, win_ptr), (void *)0);

	 mlx_loop(mlx_ptr);


	return (0);

}
