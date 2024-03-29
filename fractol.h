/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:59:50 by salee2            #+#    #+#             */
/*   Updated: 2022/09/26 18:22:49 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "minilibx_opengl_20191021/mlx.h"

# define X_END 600
# define Y_END 600
# define ITER_END 512
# define FRACTAL_TYPES 3
# define COLOR_TYPES 4
# define ESCAPE_RADIUS 4

enum e_bool
{
	FALSE,
	TRUE
};

enum e_fractal
{
	MANDELBROT,
	JULIA,
	TRICORN
};

enum e_mouse
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5
};

enum e_key
{
	ESC = 53,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	DOWN_ARROW = 125,
	UP_ARROW = 126,
};

typedef int	t_bool;

typedef struct s_cartesian
{
	int	x;
	int	y;
}	t_cartesian;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_plane_info
{
	double	size;
	double	min_to_dot;
	double	max_to_dot;
}	t_plane_info;

typedef struct s_move_info
{
	int			dir;
	double		power;
	t_complex	size;
}	t_move_info;

typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_plane
{
	double	imag_max;
	double	imag_min;
	double	real_min;
	double	real_max;
}	t_plane;

typedef struct s_fractal
{
	int			name;
	int			color_type;
	t_plane		plane;
	t_complex	z;
	t_complex	c;
}	t_fractal;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_mlx_data	img;
	t_fractal	fractal;
}	t_vars;

double		ft_atof(const char *str);
int			create_color(int color_type, int i);
t_plane		get_zoomed_plane(t_plane *plane, int x, int y, int button);
t_complex	cartesian_to_complex(int x, int y, t_plane *plane);
void		get_fractal_image(t_vars *vars);
void		my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
void		init_mlx_n_img(t_vars *vars);
void		init_fractal_arg(int argc, char ***argv, t_fractal *fractal);
void		init_fractal_plane(t_fractal *fractal);
void		init_fractal(int argc, char ***argv, t_vars *vars);
void		init(int argc, char ***argv, t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
int			red_cross(void);
int			mouse_hook(int button, int x, int y, t_vars *vars);
int			intro_fractal_type(void);

#endif //FRACTOL_H
