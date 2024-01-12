#include "../inc/fractol.h"

double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	set_julia(double *creal, double *cimaginary)
{
	*creal = generate_random_c();
	*cimaginary = generate_random_c();
}

void	check_set(t_fractal *fract, char *set)
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

void instrutions(void)
{
	ft_printf("*--------------------INSTRUCTIONS------------------------------------*\n");
	ft_printf("\n");
	ft_printf("Move with the arrow keys: Right, Up, Left, and Down\n");
	ft_printf("Zoom in and out with the + and - keys and the mouse wheel\n");
	ft_printf("Change the Julia sets with the J key\n");
	ft_printf("Change the sets with the 1, 2, 3 keys\n");
	ft_printf("Change colors with the Space key\n");
	ft_printf("Return to the default set with the R key\n");
	ft_printf("Quit the window with the Esc key\n");
	ft_printf("\n");
	ft_printf("*-------------------------------------------------------------------*\n");
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
	instrutions();
	mlx_mouse_hook(fract->window, mouse_hook, fract);
	mlx_hook(fract->window, DestroyNotify, StructureNotifyMask, kill_window, fract);
	mlx_key_hook(fract->window, handle_input, fract);
	mlx_loop(fract->mlx);
	free(fract);
	return (0);
}