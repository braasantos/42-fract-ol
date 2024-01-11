#include "../inc/fractol.h"

void check_set(t_fractal *fract, char *set)
{
	if (ft_strncmp(set, "mandelbrot", 10) == 0)
		draw_mandelbrot(fract);
	else if (ft_strncmp(set, "julia", 5) == 0)
		draw_julia(fract);
	else if (ft_strncmp(set, "burningship", 11) == 0)
		draw_burningship(fract);
	else
		exit_w_error(fract);
}
int	main(int ac, char **av)
{
	t_fractal *fract;
	int n;

	n = 1;
	fract = malloc(sizeof(t_fractal));
	if (ac == 4)
		n = realinit_fract(fract, ac, av);
	if (ac == 3 || ac > 4 || ac < 2)
		clean_exit(fract);
	fract->name = av[1];
	init_mlx(fract);
	init_fract(fract, n);
	check_set(fract, av[1]);
	mlx_mouse_hook(fract->window, mouse_hook, fract);
	mlx_hook(fract->window, DestroyNotify, StructureNotifyMask, kill_window, fract);
	mlx_key_hook(fract->window, handle_input, fract);
	mlx_loop(fract->mlx);
	free(fract);
	return (0);
}
