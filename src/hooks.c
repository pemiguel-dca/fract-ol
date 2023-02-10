/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:23:03 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/27 17:27:20 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int key, int x, int y, t_params *params)
{
	(void)x;
	(void)y;
	if (key == 5)
		params->zoom *= 1.1;
	else if (key == 4)
		params->zoom /= 1.1;
	if (!ft_strcmp(params->win_name, JULIA))
		draw_julia(params);
	else if (!ft_strcmp(params->win_name, MANDELBROT))
		draw_mandelbrot(params);
	else if (!ft_strcmp(params->win_name, SURPRISE))
		draw_surprise(params);
	return (0);
}

