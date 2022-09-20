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

//# define Y_MAX 1200
//# define X_MAX 1800
# define Y_MAX 600
# define X_MAX 900
# define ITER_MAX 1024
# define IM_SIZE 4
# define RE_SIZE 6
# define ESCAPE_RADIUS 4

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


typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	double	mul;
	t_data	img;
}	t_vars;

t_complex	cartesian_to_complex(int x, int y);
double	complex_size(t_complex comp);


#endif //FRACT_OL_H
