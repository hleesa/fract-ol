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

#include "fractol.h"

long long	tollp(const char *str, long long sign, size_t i, int *precision)
{
	long long		acc;
	const long long	llmax = LONG_LONG_MAX;

	acc = 0;
	*precision = 0;
	while (str[i])
	{
		if (acc > llmax / 10 || (acc == llmax / 10 && str[i] - '0' \
					> (llmax % 10)) || !ft_isdigit(str[i]) || *precision >= 15)
            exit(intro_fractal_type());
		acc = acc * 10 + str[i] - '0';
		++*precision;
		++i;
	}
	return (sign * acc);
}

t_bool  preprocess_to_dot(const char *str, size_t *i, long long *sign)
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
		return (FALSE);
	++*i;
	if (str[*i] != '.')
		return (FALSE);
	++*i;
	return (TRUE);
}

double	ft_atof(const char *str)
{
	size_t		i;
	long long	sign;
	long long	atol;
	double		ret;
	int			precision;

	if (preprocess_to_dot(str, &i, &sign) == FALSE || str[i] == 0)
        exit(intro_fractal_type());
	atol = tollp(str, sign, i, &precision);
	ret = atol * pow(10, -1 * precision);
	return (ret);
}
