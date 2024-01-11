#include "../inc/fractol.h"

void	clean_exit(t_fractal *fract)
{
	ft_printf("Please choose a set: mandelbrot or julia\n");
	free(fract);
	exit(1);
}

void	exit_w_error(t_fractal *fract)
{
	ft_printf("------- PLEASE CHOOSE ONE OF THE AVAIABLE SETS\n");
	ft_printf("Avaiable fractals: mandelbrot or julia\n");
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_destroy_window(fract->mlx, fract->window);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	free(fract);
	exit(0);
}

int kill_window(t_fractal *fract)
{
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_destroy_window(fract->mlx, fract->window);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	free(fract);
	exit(0);
	return (0);
}