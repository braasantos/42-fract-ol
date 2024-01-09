#include "fractol.h"

void put_pixel(t_fractal *fract, int x, int y, int color)
{
	int temp;

	temp = (y * fract->line_length) + (x * (fract->bits_per_pixel / 8));
	*((unsigned int *)(temp + fract->pointer_to_image)) = color;
}

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

void init_fract(t_fractal *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->color = 0xFCBE11;
	fract->zoom = 330;
	if (ft_strncmp(fract->name, "mandelbrot", 10) == 0)
  {
	  fract->offset_x = -2.10;
	  fract->offset_y = -1.50;
  }
	if (ft_strncmp(fract->name, "julia", 5) == 0)
  {
	  fract->offset_x = -1.60;
  	fract->zoom = 307;
	  fract->offset_y = -1.50;
  }
	fract->creal = -0.745429;
	fract->cimaginary = 0.05;
	fract->max_iterations = 60;
}