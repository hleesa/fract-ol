/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:09:28 by salee2            #+#    #+#             */
/*   Updated: 2022/09/22 14:09:29 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	intro_fractal_type(void)
{
	printf("usage : fractol [fractals] [real number] [imaginary number]\n");
	printf(" fractals :\n");
	printf(" --> mandelbrot\n");
	printf(" --> julia\n");
	printf(" --> tricorn\n");
	return (-1);
}
