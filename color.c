/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:50:25 by salee2            #+#    #+#             */
/*   Updated: 2022/09/26 10:50:32 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, \
unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	create_color(int color_type, int i)
{
	unsigned char	mono;
	unsigned char	colors[3];
	const double	t = (double)i / (double)ITER_END;

	if (color_type == 3)
	{
		mono = t * 255;
		return (create_trgb(1 - mono, mono, mono, mono));
	}
	colors[0] = (8.5 * pow((1 - t), 3) * t * 255);
	colors[1] = (15 * pow((1 - t), 2) * pow(t, 2) * 255);
	colors[2] = (9 * (1 - t) * pow(t, 3) * 255);
	return (create_trgb((t * 255), colors[color_type % 3], \
	colors[(color_type + 1) % 3], colors[(color_type + 2) % 3]));
}
