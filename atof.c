/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:19:09 by salee2            #+#    #+#             */
/*   Updated: 2022/09/23 16:19:12 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

long long	toll(const char *str, long long sign, size_t i, long long *precision)
{
	long long		acc;
	const long long	llmax = LONG_LONG_MAX;

	acc = 0;
	*precision = 0;
	while (str[i])
	{
		if (acc > llmax / 10 || (acc == llmax / 10 && str[i] - '0' \
					> (llmax % 10)) || !ft_isdigit(str[i]) || *precision > 15)
		{
			if (sign == 1)
				return (LONG_LONG_MAX);
			else
				return (LONG_LONG_MIN);
		}
		acc = acc * 10 + str[i] - '0';
		++*precision;
		++i;
	}
	return (sign * acc);
}

int	preprocess_to_dot(const char *str, size_t *i, long long *sign)
{
	*i = 0;
	*sign = 1;
	while (is_space(str[*i]))
		++*i;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		++*i;
	}
	if (str[*i] != '0')
		return (0);
	++*i;
	if (str[*i] != '.')
		return (0);
	++*i;
	return (1);
}

double	ft_atof(const char *str, int *is_error)
{
	size_t		i;
	long long	sign;
	long long	atol;
	double		ret;
	int			precision;

	if (preprocess_to_dot(str, &i, &sign) == 0)
		*is_error = 1;
	atol = toll(str, sign, i, &precision);
	if (str[i] == 0)
		*is_error = 1;
	ret = atol * pow(10, precision);
	return (ret);
}
