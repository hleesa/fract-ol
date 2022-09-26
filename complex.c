/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:53:44 by salee2            #+#    #+#             */
/*   Updated: 2022/09/20 11:53:48 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_size(t_complex comp)
{
	return (comp.real * comp.real + comp.imag * comp.imag);
}

double	button_to_power(int button)
{
	if (button == 4)
		return (0.4);
	else if (button == 5)
		return (-0.4);
	return (0);
}

t_plane	get_next_plane(t_plane plane, int x, int y, int button)
{
	t_plane			ret;
	t_plane_info	real;
	t_plane_info	imag;
	const double	power = button_to_power(button);

	imag.size = fabs(plane.imag_max - plane.imag_min);
	imag.min_to_dot = (double)(y) / (double)(Y_MAX)*imag.size;
	imag.max_to_dot = imag.size - imag.min_to_dot;
	ret.imag_max = plane.imag_max - imag.max_to_dot * power;
	ret.imag_min = plane.imag_min + imag.min_to_dot * power;
	real.size = fabs(plane.real_max - plane.real_min);
	real.min_to_dot = (double)(x) / (double)(X_MAX)*real.size;
	real.max_to_dot = real.size - real.min_to_dot;
	ret.real_max = plane.real_max - real.max_to_dot * power;
	ret.real_min = plane.real_min + real.min_to_dot * power;
	return (ret);
}

t_complex	cartesian_to_complex(int x, int y, t_plane plane)
{
	t_complex		ret;
	t_plane_info	real;
	t_plane_info	imag;

	imag.size = fabs(plane.imag_max - plane.imag_min);
	imag.min_to_dot = (double)(y) / (double)(Y_MAX)*imag.size;
	ret.imag = plane.imag_min + imag.min_to_dot;
	real.size = fabs(plane.real_max - plane.real_min);
	real.min_to_dot = (double)(x) / (double)(X_MAX)*real.size;
	ret.real = plane.real_min + real.min_to_dot;
	return (ret);
}
