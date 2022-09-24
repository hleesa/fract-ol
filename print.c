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

#include "fract-ol.h"

int	intro_fractal_type(void)
{
	printf("\nmandelbrot\n");
	printf("julia Re Im\n");
	printf("salee\n\n");
	return (-1);
}

void print_plane(t_plane *plane)
{
	printf("im max:%f, ", plane->imag_max);
	printf("im min:%f, ", plane->imag_min);
	printf("re min:%f, ", plane->real_min);
	printf("re max:%f\n", plane->real_max);
}
