/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:20:34 by salee2            #+#    #+#             */
/*   Updated: 2022/09/12 19:20:35 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"

int	main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);

	return (0);

}
