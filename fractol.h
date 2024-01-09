#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft.h"
# include "printf.h"
# include <limits.h>
# include <float.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define SIZE 960
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define ZOOM_IN 61
# define ZOOM_OUT 45
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_PLUS 69  // Adjust with the actual keycode for '+'
# define KEY_MINUS 78 // Adjust with the actual keycode for '-'
# define KEY_PAD_PLUS 65451 // Adjust with the actual keycode for numpad '+'
# define KEY_PAD_MINUS 65453 // Adjust with the actual keycode for numpad '-'

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char		*pointer_to_image;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	double	zreal;
	double	zimaginary;
	double	creal;
	double	cimaginary;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;


void put_pixel(t_fractal *fract, int x, int y, int color);
void handle_input2(int keysym, t_fractal *fract);
void get_directions(int n, t_fractal *fract);
void change_sets(t_fractal *fract, char set);
void get_zoom(int n, t_fractal *fract);
void ft_mandelbrot(t_fractal *fract);
void exit_w_error(t_fractal *fract);
void init_fract(t_fractal *fract);
void ft_julia(t_fractal *fract);
void init_mlx(t_fractal *fract);
int draw_fractal(t_fractal *fract, char *set);
int draw_fractal(t_fractal *fract, char *set);
int handle_input(int keysym, t_fractal *fract);
#endif
