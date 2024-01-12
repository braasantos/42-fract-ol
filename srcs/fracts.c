/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:03:14 by bjorge-m          #+#    #+#             */
/*   Updated: 2024/01/12 21:06:40 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	burning_ship(t_fractal *fract)
{
	double	x_temp;

	fract->i = 0;
	fract->zreal = 0.0;
	fract->zimaginary = 0.0;
	fract->creal = (fract->x / fract->zoom) + fract->offset_x;
	fract->cimaginary = (fract->y / fract->zoom) + fract->offset_y;
	while (++fract->i < fract->max_iterations)
	{
		x_temp = fract->zreal * fract->zreal - 
			fract->zimaginary * fract->zimaginary + 
			fract->creal;
		fract->zimaginary = fabs(2.0 * fract->zreal * 
				fract->zimaginary) + fract->cimaginary;
		fract->zreal = fabs(x_temp);
		if (fract->zreal * fract->zreal + 
			fract->zimaginary * fract->zimaginary 
			>= __DBL_MAX__)
			break ;
	}
	if (fract->i == fract->max_iterations)
		put_pixel(fract, fract->x, fract->y, 0x000000);
	else
		put_pixel(fract, fract->x, 
			fract->y, (fract->color * fract->i * 4));
}

void	mandelbrot(t_fractal *fract)
{
	int		i;
	double	x_temp;

	i = 0;
	fract->zreal = 0;
	fract->zimaginary = 0;
	fract->creal = (fract->x / fract->zoom) + fract->offset_x;
	fract->cimaginary = (fract->y / fract->zoom) + fract->offset_y;
	while (++i < fract->max_iterations)
	{
		x_temp = fract->zreal * fract->zreal - 
			fract->zimaginary * fract->zimaginary 
			+ fract->creal;
		fract->zimaginary = 2.0 * fract->zreal * 
			fract->zimaginary + fract->cimaginary;
		fract->zreal = x_temp;
		if (fract->zreal * fract->zreal + 
			fract->zimaginary * fract->zimaginary 
			>= __DBL_MAX__)
			break ;
	}
	if (i == fract->max_iterations)
		put_pixel(fract, fract->x, fract->y, 0x000000);
	else
		put_pixel(fract, fract->x, fract->y, (fract->color * i * 4));
}

void	julia(t_fractal *fract)
{
	int		i;
	double	tmp;

	fract->zreal = fract->x / fract->zoom + fract->offset_x;
	fract->zimaginary = fract->y / fract->zoom + fract->offset_y;
	i = 0;
	while (++i < fract->max_iterations)
	{
		tmp = fract->zreal;
		fract->zreal = fract->zreal * fract->zreal - 
			fract->zimaginary * fract->zimaginary + 
			fract->creal;
		fract->zimaginary = 2 * fract->zimaginary * 
			tmp + fract->cimaginary;
		if (fract->zreal * fract->zreal + 
			fract->zimaginary * fract->zimaginary 
			>= __DBL_MAX__)
			break ;
	}
	if (i == fract->max_iterations)
		put_pixel(fract, fract->x, fract->y, 0x000000);
	else
		put_pixel(fract, fract->x, fract->y, (fract->color * i * 4));
}
