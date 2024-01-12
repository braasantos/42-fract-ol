#include "../inc/fractol.h"

void	clean_exit(t_fractal *fract)
{
	ft_printf("Please choose a set: Mandelbrot, Julia, or Burningship\n");
	ft_printf("You can select an additional value for the Julia set.\n");
	ft_printf("\n");
	ft_printf("---------- Example ----------\n");
	ft_printf("./fractol <julia> <numeric value> <numeric value> \n");
	free(fract);
	exit(1);
}

void	exit_w_error(t_fractal *fract)
{
	ft_printf("\n");
	ft_printf("------- PLEASE CHOOSE ONE OF THE AVAILABLE SETS -------\n");
	ft_printf("- Available fractals: Mandelbrot, Julia or Burningship -\n");
	ft_printf("\n");
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_destroy_window(fract->mlx, fract->window);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	free(fract);
	exit(0);
}

int	kill_window(t_fractal *fract)
{
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_destroy_window(fract->mlx, fract->window);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	free(fract);
	exit(0);
	return (0);
}
