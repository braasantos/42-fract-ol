/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:02:56 by bjorge-m          #+#    #+#             */
/*   Updated: 2024/01/12 20:02:59 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	draw_mandelbrot(t_fractal *fract)
{
	fract->x = 0;
	fract->y = 0;
	while (fract->x < SIZE)
	{
		while (fract->y < SIZE)
		{
			mandelbrot(fract);
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->image, 0, 0);
	return (0);
}

int	draw_julia(t_fractal *fract)
{
	fract->x = 0;
	fract->y = 0;
	while (fract->x < SIZE)
	{
		while (fract->y < SIZE)
		{
			julia(fract);
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->image, 0, 0);
	return (0);
}

int	draw_burningship(t_fractal *fract)
{
	fract->x = 0;
	fract->y = 0;
	while (fract->x < SIZE)
	{
		while (fract->y < SIZE)
		{
			burning_ship(fract);
			fract->y++;
		}
		fract->x++;
		fract->y = 0;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->image, 0, 0);
	return (0);
}
