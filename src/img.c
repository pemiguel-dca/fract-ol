/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:26:53 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/25 17:39:29 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_image(t_params *params)
{
	params->img = mlx_new_image(params->mlx_ptr, WIDTH, HEIGHT);
	if (!params->img)
	{
		ft_putstr_fd("Failed to create the image!", STDERR_FILENO);
		exit(0);
	}
	params->addr = mlx_get_data_addr(params->img, &params->bits, &params->line_length, &params->endian);
}

void my_mlx_pixel_put(t_params *img, int x, int y, int iterations)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits / 8));
	*(unsigned int*)dst = iterations;
}
