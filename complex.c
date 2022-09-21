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
	const double imag = (double)y* (double)IM_SIZE / (double)Y_MAX - (double)IM_SIZE / 2.0;
	const double real = (double)x* (double)RE_SIZE / (double )X_MAX - (double)RE_SIZE / 2.0;
	return ((t_complex){real, imag});
}

double	abs_d(double src)
{
	if (src < 0 )
		return -src;
	return src;
}

double button_to_power(int button)
{
	if(button == 4)
		return (0.2);
	else if (button == 5)
		return (-0.2);
	return (1);
}

t_plane	get_next_plane(t_plane plane, int x, int y, int button)
{
	double power = button_to_power(button);

	double imag_size = abs_d(plane.imag_max - plane.imag_min);
	double imag_min_to_dot = (double)(y) / (double)(Y_MAX) * imag_size;
	double imag_max_to_dot = imag_size - imag_min_to_dot;
	double imag_max = plane.imag_max - imag_max_to_dot * power;
	double imag_min = plane.imag_min + imag_min_to_dot * power;

	double real_size = abs_d(plane.real_max - plane.real_min);
	double real_min_to_dot = (double)(x) / (double)(X_MAX) * real_size;
	double real_max_to_dot = real_size - real_min_to_dot;
	double real_max = plane.real_max - real_max_to_dot * power;
	double real_min = plane.real_min + real_min_to_dot * power;

	return (t_plane){imag_max, imag_min, real_min, real_max};
}

t_complex	cartesian_to_complex2(int x, int y, int button, t_plane plane)
{
	const double imag_size = abs_d(plane.imag_max - plane.imag_min);
	double imag_min_to_dot = (double)(y) / (double)(Y_MAX) * imag_size;
	double imag = plane.imag_min + imag_min_to_dot;

	const double real_size = abs_d(plane.real_max - plane.real_min);
	double real_min_to_dot = (double)(x) / (double)(X_MAX) * real_size;
	double real = plane.real_min + real_min_to_dot;
	return ((t_complex){real, imag});
}