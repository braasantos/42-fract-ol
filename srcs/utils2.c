/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:03:19 by bjorge-m          #+#    #+#             */
/*   Updated: 2024/01/12 20:24:11 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_isspecial(char c)
{
	if (c == '!' || c == '~')
		return (1);
	if (c == '@' || c == '#')
		return (1);
	if (c == '^' || c == '$')
		return (1);
	if (c == '&' || c == '*')
		return (1);
	if (c == '(' || c == ')')
		return (1);
	if (c == '_' || c == '~')
		return (1);
	if (c == '=' || c == '\\')
		return (1);
	if (c == '[' || c == ']')
		return (1);
	if (c == '|' || c == '"')
		return (1);
	if (c == '{' || c == '{')
		return (1);
	if (c == '\'')
		return (1);
	return (0);
}

void	check_args(char *str, t_fractal *fract)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			clean_exit(fract);
		if (ft_isspecial(str[i]) == 1)
			clean_exit(fract);
		i++;
	}
}

void	put_pixel(t_fractal *fract, int x, int y, int color)
{
	int	temp;

	temp = (y * fract->line_length) + (x * (fract->bits_per_pixel / 8));
	*((unsigned int *)(temp + fract->pointer_to_image)) = color;
}

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
	check_set(fract, fract->name);
}

void	get_zoom_mouse(int n, t_fractal *fract, int x, int y)
{
	double	zoom_factor;

	zoom_factor = 1.42;
	if (n == 1)
	{
		fract->offset_x = (x / fract->zoom + 
				fract->offset_x) - (x / (fract->zoom * 
					zoom_factor));
		fract->offset_y = (y / fract->zoom + 
				fract->offset_y) - (y / (fract->zoom * 
					zoom_factor));
		fract->zoom *= zoom_factor;
	}
	else
	{
		fract->offset_x = (x / fract->zoom + 
				fract->offset_x) - (x / (fract->zoom / 
					zoom_factor));
		fract->offset_y = (y / fract->zoom + 
				fract->offset_y) - (y / (fract->zoom / 
					zoom_factor));
		fract->zoom /= zoom_factor;
	}
	check_set(fract, fract->name);
}
