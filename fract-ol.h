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
#include <math.h>
#include "minilibx_opengl_20191021/mlx.h"

//# define Y_MAX 1200
//# define X_MAX 1800
# define Y_MAX 600
# define X_MAX 600
# define ITER_MAX 1024
# define IM_SIZE 4
# define RE_SIZE 6
# define ESCAPE_RADIUS 4
# define SCROLL_UP 4
# define SCROLL_DOWN 5

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


typedef struct s_plane
{
	double imag_max;
	double imag_min;
	double real_min;
	double real_max;
}	t_plane;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	double	mul;
	t_data	img;
	t_plane plane;
}	t_vars;

double	complex_size(t_complex comp);
t_complex	cartesian_to_complex(int x, int y, t_plane plane);
double button_to_power(int button);
t_plane	get_next_plane(t_plane plane, int x, int y, int button);


#endif //FRACT_OL_H
