/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:32:40 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/27 16:02:29 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(char *name, t_params *params)
{
	if (!ft_strcmp(name, JULIA))
			draw_julia(params);
	if (!ft_strcmp(name, MANDELBROT))
		draw_mandelbrot(params);
	if (!ft_strcmp(name, SURPRISE))
		draw_surprise(params);
}

int	confirm_params(int n_params, char **argv)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if ((n_params == 3 && !ft_strcmp(argv[1], JULIA))
		|| (n_params == 1 && !ft_strcmp(argv[1], MANDELBROT))
		|| (n_params == 1 && !ft_strcmp(argv[1], SURPRISE)))
	{
		if ((n_params == 3 && !ft_strcmp(argv[1], JULIA)))
		{
			while (++j < n_params)
			{
				i = 0;
				while (argv[j][i])
				{
					if (!ft_strchr(DEC_BASE, argv[j][i++]))
						return (1);
				}
			}
		}
	}
	else
		return (1);
	return (0);
}

int main(int argc, char *argv[])
{
	t_params	params;

	if (!confirm_params((argc - 1), argv))
	{
		start_window(&params, ft_strjoin(argv[1], " Set"));
		start_image(&params);
		if (argc == 4)
		{
			params.real_c = ft_atof(argv[2]);
			params.imaginary_c = ft_atof(argv[3]);
			params.color = 0xf2f9f1;
		}
		draw(argv[1], &params);
		mlx_mouse_hook(params.mlx_win, &mouse_zoom, (void*)&params);
		mlx_hook(params.mlx_win, 2, (1L << 0), &keys_pressed, &params);
		mlx_hook(params.mlx_win, 17, 0, &top_right, 0);
		mlx_loop(params.mlx_ptr);
	}
	else
		requirements();
	return (0);
}
