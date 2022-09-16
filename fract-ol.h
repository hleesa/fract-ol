/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:59:50 by salee2            #+#    #+#             */
/*   Updated: 2022/09/14 15:59:54 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H

#include <unistd.h>
#include "minilibx_opengl_20191021/mlx.h"

# define YMAX 1200
# define XMAX 1800
# define IM_SIZE 4
# define RE_SIZE 6

typedef int t_bool;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

enum e_bool
{
	FALSE,
	TRUE
};

#include <stdio.h>
#include <limits.h>
#include <float.h>

#endif //FRACT_OL_H
