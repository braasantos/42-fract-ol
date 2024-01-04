#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h> 
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft.h"
# include "printf.h"
# include <stdarg.h>

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


typedef struct  s_fractal
{
    void    *mlx;
    void    *win;
    void    *image;
    int     x;
    int     y;
}               t_fractal;
#endif
