/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:57:30 by pemiguel          #+#    #+#             */
/*   Updated: 2023/02/10 20:57:35 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keys_pressed(int key, t_params *params)
{
	if (key == ESC)
		exit(0);
	if (key == ARROW_DOWN)
		params->y_arrow -= 10;
	if (key == ARROW_UP)
		params->y_arrow += 10;
	if (key == ARROW_RIGHT)
		params->x_arrow -= 10;
	if (key == ARROW_LEFT)
		params->x_arrow += 10;
	if (key == PLUS)
		params->color += 1;
	if (key == MINUS && params->color - 1 > 0)
		params->color -= 1;
	if (!ft_strcmp(params->win_name, JULIA))
		draw_julia(params);
	else if (!ft_strcmp(params->win_name, MANDELBROT))
		draw_mandelbrot(params);
	else if (!ft_strcmp(params->win_name, SURPRISE))
		draw_surprise(params);
	return (0);
}

