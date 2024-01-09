#include "fractol.h"

void get_zoom(int n, t_fractal *fract)
{
	double	zoom_in_factor;
	double	zoom_out_factor;

	zoom_in_factor = 1.2;
	zoom_out_factor = 1.2;
	if (n == 1)
		fract->zoom *= zoom_in_factor;
	else
		fract->zoom /= zoom_out_factor;
	draw_fractal(fract, fract->name);
}
void get_directions(int n, t_fractal *fract)
{
	double move_factor = 0.05;
	if (n == 1) // esquerda
		fract->offset_x -= move_factor;
	else if (n == 2) // direita
		fract->offset_x += move_factor;
	else if (n == 3) // cima
    fract->offset_y -= move_factor;
  else if (n == 4) // baixo
    fract->offset_y += move_factor;
  draw_fractal(fract, fract->name);
}

int handle_input(int keysym, t_fractal *fract)
{
    if (keysym == ZOOM_IN || keysym == XK_KP_Add)
        get_zoom(1, fract);
    else if (keysym == ZOOM_OUT || keysym == XK_KP_Subtract)
        get_zoom(2, fract);
    else if (keysym == XK_Escape)
    {
        mlx_destroy_image(fract->mlx, fract->image);
        mlx_destroy_window(fract->mlx, fract->window);
        mlx_destroy_display(fract->mlx);
        free(fract->mlx);
        exit(0);
    }
    else if (keysym == XK_Left || keysym == XK_KP_Left)
        get_directions(1, fract);
    else if (keysym == XK_Right || keysym == XK_KP_Right)
        get_directions(2, fract);
    else if (keysym == XK_Up || keysym == XK_KP_Up)
        get_directions(3, fract);
    else if (keysym == XK_Down || keysym == XK_KP_Down)
        get_directions(4, fract);
    return (0);
}


void put_pixel(t_fractal *fract, int x, int y, int color)
{
	int temp;

	temp = (y * fract->line_length) + (x * (fract->bits_per_pixel / 8));
	*((unsigned int *)(temp + fract->pointer_to_image)) = color;
}

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
		put_pixel(fract, fract->x, fract->y, (fract->color * i));
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
		put_pixel(fract, fract->x, fract->y, (fract->color * (i % 255)));
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
			{
				if (!fract->creal && !fract->cimaginary)
				{
					fract->creal = -0.745429;
					fract->cimaginary = 0.05;
				}
				ft_julia(fract);
			}
			else
			{
				ft_printf("Avaliable fractals: mandelbrot or julia\n");
				exit(0);
			}
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->image, 0, 0);
	return (0);
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
	fract->offset_x = -2.10;
	fract->offset_y = -1.50;
	fract->max_iterations = 60;
}
int main(int ac, char **av)
{
	t_fractal *fract;

	fract = malloc(sizeof(t_fractal));
	if (ac != 2)
		return (ft_printf("Please choose a set: mandelbrot or julia\n"), 0);
	fract->name = av[1];
	init_mlx(fract);
	init_fract(fract);
	draw_fractal(fract, av[1]);
	mlx_key_hook(fract->window, handle_input, fract);
	mlx_loop(fract->mlx);
	free(fract);
	return (0);
}