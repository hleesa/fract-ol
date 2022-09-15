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
	return 0;
}

//
//int deal_key(int key, void *param)
//{
//	ft_putchar('x');
//	return 0;
//}

int	main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xffffff);
//	mlx_key_hook(win_ptr, deal_key,(void *)0);
	mlx_key_hook(win_ptr, deal_key( 0, mlx_ptr, win_ptr), (void *)0);

	 mlx_loop(mlx_ptr);


	return (0);

}
