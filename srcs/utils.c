#include "../inc/fractol.h"

void init_mlx(t_fractal *fract)
{
	fract->mlx = mlx_init(); // inicia a minilibx library
	fract->window = mlx_new_window(fract->mlx, SIZE, SIZE, fract->name);
	if (fract->window == NULL)
	{
		free(fract->window);
		free(fract->mlx);
		exit(EXIT_FAILURE);
	}
	fract->image = mlx_new_image(fract->mlx, SIZE, SIZE);
	fract->pointer_to_image = mlx_get_data_addr(fract->image, &fract->bits_per_pixel, &fract->line_length, &fract->endian);
}
int realinit_fract(t_fractal *fract, int ac, char **av)
{
	if (ac == 4 && strncmp(av[1], "julia", 5) == 0)
	{
		check_args(av[2], fract);
		check_args(av[3], fract);
		fract->creal = atof(av[2]);
		fract->cimaginary = atof(av[3]);
	}
	else
	{
		fract->creal = 0;
		fract->cimaginary = 0;
	}
	return (0);
}

void init_fract(t_fractal *fract, int n)
{
	fract->x = 0;
	fract->y = 0;
	fract->color = 1;
	fract->zoom = 300;
	if (ft_strncmp(fract->name, "mandelbrot", 10) == 0)
	{
		fract->offset_x = -2.10;
		fract->offset_y = -1.50;
	}
	if (ft_strncmp(fract->name, "julia", 5) == 0)
	{
		fract->offset_x = -1.60;
		fract->offset_y = -1.50;
		if (n == 1)
		{
			fract->creal = -0.80;
			fract->cimaginary = 0.156;
		}
	}
	if (ft_strncmp(fract->name, "burning", 6) == 0)
	{
		fract->offset_x = -2.10;
		fract->offset_y = -2.00;
	}
	fract->max_iterations = 60;
}

static int skip_space_sign(char *str, int *is_neg)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}
double ft_atof(char *str)
{
	int i;
	double nb;
	int is_neg;
	double div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (nb * is_neg);
}
