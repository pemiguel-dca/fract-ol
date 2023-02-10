/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:56:00 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/27 23:33:38 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	max_iterations_surprise(complex z)
{
	int		i;
	double	point;
	complex	c;

	i = -1;
	point = 0;
	c.i = z.i;
	c.r = z.r;
	while (++i < MAX_ITERATIONS)
	{
		point = z.r * z.r - z.i * z.i + c.r;
		z.i = fabs(2 * z.r * z.i) + c.i;
		z.r = fabs(point);
		if (z.r * z.r + z.i * z.i > 4)
			return (i * 255);
	}
	return (0);
}

void	draw_surprise(t_params *params)
{
	complex	z;
	int		x;
	int		y;
	int		iterations;

	x = -1;
	y = -1;
	iterations = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z.r = params->zoom * 2 * (x + params->x_arrow - WIDTH / 2) / (WIDTH / 2);
			z.i = params->zoom * 2 *(y + params->y_arrow - HEIGHT / 2) / (HEIGHT / 2);
			iterations = max_iterations_surprise(z);
			if (iterations == 0)
				my_mlx_pixel_put(params, x, y, 0x000000);
			else
				my_mlx_pixel_put(params, x, y, (iterations * 100 +params->color));
		}
	}
	mlx_put_image_to_window(params->mlx_ptr, params->mlx_win, params->img, 0, 0);

}

