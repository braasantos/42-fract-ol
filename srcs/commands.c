#include "../inc/fractol.h"

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fract)
{
	if (mouse_code == SCROLL_UP)
		get_zoom_mouse(1, fract, x, y);
	else if (mouse_code == SCROLL_DOWN)
		get_zoom_mouse(-1, fract, x, y);
	check_set(fract, fract->name);
	return (0);
}

void	get_directions(int n, t_fractal *fract)
{
	if (n == 1) // esquerda
		fract->offset_x -= 42 / fract->zoom;
	else if (n == 2) // direita
		fract->offset_x +=  42 / fract->zoom;
	else if (n == 3) // cima
		fract->offset_y -=  42 / fract->zoom;
	else if (n == 4) // baixo
		fract->offset_y +=  42 / fract->zoom;
	check_set(fract, fract->name);
}

void	change_sets(t_fractal *fract, char set)
{
	if (set == 'J')
		fract->name = "julia";
	else if (set == 'M')
		fract->name = "mandelbrot";
	else
		fract->name = "burningship";
	init_fract(fract, 1);
	check_set(fract, fract->name);
}

int	handle_input(int keysym, t_fractal *fract)
{
	if (keysym == ZOOM_IN || keysym == XK_KP_Add)
		get_zoom(1, fract);
	else if (keysym == ZOOM_OUT || keysym == XK_KP_Subtract)
		get_zoom(2, fract);
	if (keysym == XK_Escape)
		kill_window(fract);
	else if (keysym == XK_space)
	{
		fract->color += (255 * 255 * 255) / 100;
		check_set(fract, fract->name);
	}
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
	else if (keysym == 51)
		change_sets(fract, 'X');
	else if (keysym == 114)
	{
		init_fract(fract, 1);
		check_set(fract, fract->name);
	}
	
}
