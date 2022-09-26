/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:59:50 by salee2            #+#    #+#             */
/*   Updated: 2022/09/26 15:18:55 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "minilibx_opengl_20191021/mlx.h"

# define Y_MAX 600
# define X_MAX 600
# define ITER_MAX 512
# define IM_SIZE 4
# define RE_SIZE 6
# define MANDELBROT_ESCAPE_RADIUS 4
# define JULIA_ESCAPE_RADIUS 4
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define PARAM_END 4
# define FRACTAL_TYPES 3
# define COLOR_TYPES 4
# define RIGHT_CLICK 2

#define KEY_W 13    // MacOS의 키보드 코드들이다.
#define KEY_A 0     //
#define KEY_S 1     // 위에서 부터 차례대로
#define KEY_D 2     //
#define KEY_ESC 53  // 'W' 'A' 'S' 'D' 'ESC'들의 키보드 코드이다.

typedef int t_bool;
//typedef struct s_cartesian
//{
//    int x;
//    int y;
//}   t_cartesian;

typedef struct s_complex
{
    double	real;
    double	imag;
}	t_complex;

typedef struct s_plane_info
{
	double size;
	double min_to_dot;
	double max_to_dot;
	double max;
	double min;
}	t_plane_info;

typedef struct s_move_info
{
	int dir;
	double power;
	t_complex size;
}	t_move_info;

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

typedef struct s_fractal
{
    int depth;
    int	name;
    int color_type;
    t_plane scope;
    t_complex z;
    t_complex c;
}	t_fractal;

typedef struct	s_vars {
    void	*mlx;
    void	*win;
    t_data	img;
    t_fractal fractal;
    int     (*frt_ptr)(struct s_vars *vars, int y, int x);
}	t_vars;


enum e_fractal
{
    MANDELBROT,
    JULIA,
    SALEE
};


double	complex_size(t_complex comp);
t_complex	cartesian_to_complex(int x, int y, t_plane plane);
double button_to_power(int button);
t_plane	get_next_plane(t_plane plane, int x, int y, int button);
void	init_vars(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
//int create_color(double mag, int depth);
void	get_julia_image(t_vars *vars);

int	intro_fractal_type(void);
double	ft_atof(const char *str);
void	init_fractal_arg(int argc, char ***argv, t_fractal *fractal);
void    init_fractal_scope(t_fractal *fractal);

//void	get_mandelbrot_image(t_vars *vars);
void	get_fractal_image(t_vars *vars);
int     get_mandelbrot_element(t_vars *vars, int x, int y);
int     get_julia_element(t_vars *vars, int x, int y);
int     get_salee_element(t_vars *vars, int x, int y);
void    init_fractal_ptr(t_vars *vars);


int create_color(int color_type, int i);
int	mouse_hook(int button, int x, int y, t_vars *vars);
int	key_hook(int keycode, t_vars *vars);
int     get_salee_element(t_vars *vars, int y, int x);


void print_plane(t_plane *plane);
#include <limits.h>
#include <float.h>

#endif //FRACT_OL_H
