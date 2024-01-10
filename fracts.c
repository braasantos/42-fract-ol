#include "fractol.h"

void ft_mandelbrot(t_fractal *fract)
{
	int i;
	double x_temp;

	i = 0;
	fract->zreal = 0;
	fract->zimaginary = 0;
	fract->creal = (fract->x / fract->zoom) + fract->offset_x;
	fract->cimaginary = (fract->y / fract->zoom) + fract->offset_y;
	while (++i < fract->max_iterations)
	{
		x_temp = fract->zreal * fract->zreal - fract->zimaginary * fract->zimaginary + fract->creal;
		fract->zimaginary = 2.0 * fract->zreal * fract->zimaginary + fract->cimaginary;
		fract->zreal = x_temp;
		if (fract->zreal * fract->zreal + fract->zimaginary * fract->zimaginary >= __DBL_MAX__)
			break; // Escape if it diverges
	}
	if (i == fract->max_iterations)
		put_pixel(fract, fract->x, fract->y, 0x000000);
	else
		put_pixel(fract, fract->x, fract->y, (i * 4));
}

void ft_julia(t_fractal *fract)
{
	int i;
	double tmp;

	fract->name = "julia";
	fract->zreal = fract->x / fract->zoom + fract->offset_x;
	fract->zimaginary = fract->y / fract->zoom + fract->offset_y;
	i = 0;
	while (++i < fract->max_iterations)
	{
		tmp = fract->zreal;
		fract->zreal = fract->zreal * fract->zreal - fract->zimaginary * fract->zimaginary + fract->creal;
		fract->zimaginary = 2 * fract->zimaginary * tmp + fract->cimaginary;
		if (fract->zreal * fract->zreal + fract->zimaginary * fract->zimaginary >= __DBL_MAX__)
			break;
	}
	if (i == fract->max_iterations)
		put_pixel(fract, fract->x, fract->y, 0x000000);
	else
			put_pixel(fract, fract->x, fract->y, (i * 4));
}

int draw_fractal(t_fractal *fract, char *set)
{
	fract->x = 0;
	fract->y = 0;
	while (fract->x < SIZE)
	{
		while (fract->y < SIZE)
		{
			if (ft_strncmp(set, "mandelbrot", 10) == 0)
				ft_mandelbrot(fract);
			else if (ft_strncmp(set, "julia", 5) == 0)
					ft_julia(fract);
			else
				exit_w_error(fract);
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->image, 0, 0);
	return (0);
}
