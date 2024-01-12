/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:04:20 by bjorge-m          #+#    #+#             */
/*   Updated: 2024/01/12 21:05:33 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../includes/LIBFT/libft.h"
# include <math.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>

/* KEY CODES */
# define SIZE 960
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ZOOM_IN 61
# define ZOOM_OUT 45
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	int		i;
	char	*pointer_to_image;
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
}		t_fractal;

/* SETS */
void	burning_ship(t_fractal *fract);
void	mandelbrot(t_fractal *fract);
void	julia(t_fractal *fract);
int		draw_burningship(t_fractal *fract);
int		draw_mandelbrot(t_fractal *fract);
int		draw_julia(t_fractal *fract);
/* EVENTS */
void	instrutions(void);
void	handle_input2(int keysym, t_fractal *fract);
void	put_pixel(t_fractal *fract, int x, int y, int color);
int		handle_input(int keysym, t_fractal *fract);
int		mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
/* ADD CHANGES */
void	change_sets(t_fractal *fract, char set);
void	get_zoom(int n, t_fractal *fract);
void	get_directions(int n, t_fractal *fract);
void	get_zoom_mouse(int n, t_fractal *fract, int x, int y);
void	set_julia(double *creal, double *cimaginary);
double	generate_random_c(void);
/* INIT EVERYTHING */
void	init_fract(t_fractal *fract, int n);
int		realinit_fract(t_fractal *fract, int ac, char **av);
void	init_mlx(t_fractal *fract);
/* CHECKS */
void	check_set(t_fractal *fract, char *set);
void	check_args(char *str, t_fractal *fract);
int		ft_isspecial(char c);
double	ft_atof(char *str);
int		skip_space_sign(char *str, int *is_neg);
/* EXIT */
void	exit_w_error(t_fractal *fract);
void	clean_exit(t_fractal *fract);
int		kill_window(t_fractal *fract);
#endif
