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
