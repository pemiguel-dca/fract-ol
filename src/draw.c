/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:32:40 by pemiguel          #+#    #+#             */
/*   Updated: 2023/02/10 20:49:00 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		max_iterations(complex z, complex c)
{
	int		i;
	double	point;

	i = -1;
	point = 0;
	while (++i < MAX_ITERATIONS)
	{
		point = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = point;
		if (z.r * z.r + z.i * z.i > 4)
			return (i);
	}
	return (0);
}

void	draw_julia(t_params *params)
{
	complex	z;
	complex	c;
	int		x;
	int		y;
	int		iterations;

	x = -1;
	y = -1;
	c.r = params->real_c;
	c.i = params->imaginary_c;
	iterations = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z.r = params->zoom * 2 * (x + params->x_arrow - WIDTH / 2) / (WIDTH / 2);
			z.i = params->zoom * 2 * (y + params->y_arrow - HEIGHT / 2) / (HEIGHT / 2);
			iterations = max_iterations(z, c);
			my_mlx_pixel_put(params, x, y, iterations * params->color / 3);
			if (iterations == 0)
				my_mlx_pixel_put(params, x, y, 0);
		}
	}
	mlx_put_image_to_window(params->mlx_ptr, params->mlx_win, params->img, 0, 0);
}

int		max_iterations_mandelbrot(complex z)
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
		point = c.r * c.r - c.i * c.i + z.r;
		c.i = 2 * c.r * c.i + z.i;
		c.r = point;
		if (c.r * c.r + c.i * c.i > 4)
			return (i * 255);
	}
	return (0);
}

void	draw_mandelbrot(t_params *params)
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
			z.r = params->zoom * 2 * (x + params->x_arrow - WIDTH / 1.7) / (WIDTH / 1.7);
			z.i = params->zoom * 2 * (y + params->y_arrow- HEIGHT / 2) / (HEIGHT / 2);
			iterations = max_iterations_mandelbrot(z);
			my_mlx_pixel_put(params, x, y, (iterations * 100031 * params->color));
			if (iterations == 0)
				my_mlx_pixel_put(params, x, y, 0);
		}
	}
	mlx_put_image_to_window(params->mlx_ptr, params->mlx_win, params->img, 0, 0);
}
