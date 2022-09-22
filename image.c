/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:34:26 by salee2            #+#    #+#             */
/*   Updated: 2022/09/22 13:34:28 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	create_trgb2(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int create_color(double t)
{
	unsigned char r = (8.5 * pow((1 - t), 3) * t * 255);
	unsigned char g = (15 * pow((1 - t), 2) * pow(t, 2) * 255);
	unsigned char b = (9 * (1 - t) * pow(t, 3) * 255);
	int color = create_trgb(t, r, g, b);
	return color;
}