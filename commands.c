#include "fractol.h"

void	get_zoom(int n, t_fractal *fract)
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

void	get_directions(int n, t_fractal *fract)
{
	double move_factor;

	move_factor = 0.05;
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

void	change_sets(t_fractal *fract, char set)
{
	if (set == 'J')
		fract->name = "julia";
	else
		fract->name = "mandelbrot";
	init_fract(fract);
	draw_fractal(fract, fract->name);
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
int	handle_input(int keysym, t_fractal *fract)
{
	if (keysym == ZOOM_IN || keysym == XK_KP_Add)
		get_zoom(1, fract);
	else if (keysym == ZOOM_OUT || keysym == XK_KP_Subtract)
		get_zoom(2, fract);
	else if (keysym == XK_Escape)
		kill_window(fract);
	// else if (keysym == XK_space)
	// 	get_color(fract);
	else
		handle_input2(keysym, fract);
	return (0);
}

void	handle_input2(int keysym, t_fractal *fract)
{
	if (keysym == XK_Left || keysym == XK_KP_Left)
		get_directions(1, fract);
	else if (keysym == XK_Right || keysym == XK_KP_Right)
		get_directions(2, fract);
	else if (keysym == XK_Up || keysym == XK_KP_Up)
		get_directions(3, fract);
	else if (keysym == XK_Down || keysym == XK_KP_Down)
		get_directions(4, fract);
	else if (keysym == 49)
		change_sets(fract, 'M');
	else if (keysym == 50)
		change_sets(fract, 'J');
}
