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

//# define YMAX 1200
//# define XMAX 1800
# define YMAX 600
# define XMAX 900
#
# define IM_SIZE 4
# define RE_SIZE 6

typedef int t_bool;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_mouse_data
{
	int button;
	int x;
	int y;
}	t_mouse_data;

enum e_bool
{
	FALSE,
	TRUE
};

#include <stdio.h>
#include <limits.h>
#include <float.h>



typedef struct	s_vars {
	void	*mlx;
	void	*win;
	double	mul;
}				t_vars;


#endif //FRACT_OL_H
