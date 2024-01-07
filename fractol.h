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

# define HEIGHT 1000
# define WIDTH 1000
#define MAX_ITERATIONS 1000
# define SIZE 700
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
# define M 46
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_PLUS 69  // Adjust with the actual keycode for '+'
# define KEY_MINUS 78 // Adjust with the actual keycode for '-'
# define KEY_PAD_PLUS 65451 // Adjust with the actual keycode for numpad '+'
# define KEY_PAD_MINUS 65453 // Adjust with the actual keycode for numpad '-'


// typedef struct	s_fractal
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*image;
// 	char	*name;
// 	int		x;
// 	int		y;
// }		t_fractal;

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


void draw_fractal(t_fractal *fract, char *set);
#endif
