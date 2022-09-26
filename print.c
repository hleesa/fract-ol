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
	printf("\nmandelbrot\n");
	printf("julia Re Im\n");
	printf("tricorn\n\n");
	return (-1);
}

void	print_plane(t_plane *plane)
{
	printf("im max:%.15f, ", plane->imag_max);
	printf("im min:%.15f, ", plane->imag_min);
	printf("re min:%.15f, ", plane->real_min);
	printf("re max:%.15f\n", plane->real_max);
}
