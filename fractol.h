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



typedef struct  s_fractal
{
    void    *mlx;
    void    *win;
    void    *image;
    int     x;
    int     y;
}               t_fractal;
#endif
