#include "fractol.h"
void clean_exit(t_fractal *fract)
{
	ft_printf("Please choose a set: mandelbrot or julia\n");
	free(fract);
	exit(1);
}
void exit_w_error(t_fractal *fract)
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

int main(int ac, char **av)
{
	t_fractal *fract;

	fract = malloc(sizeof(t_fractal));
	if (ac != 2)
		clean_exit(fract);
	fract->name = av[1];
	init_mlx(fract);
	init_fract(fract);
	draw_fractal(fract, av[1]);
	mlx_key_hook(fract->window, handle_input, fract);
	mlx_loop(fract->mlx);
	free(fract);
	return (0);
}