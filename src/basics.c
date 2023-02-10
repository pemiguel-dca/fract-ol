/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:19:59 by pemiguel          #+#    #+#             */
/*   Updated: 2023/01/27 18:00:29 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	requirements()
{
	ft_putstr_fd("In this program you well be able to experience absolute beauty.\n", 1);
	ft_putstr_fd("You have to choose, that choice being the \033[0;37m\e[1mfirst argument\033[0;m\e[m, which set would you like to explore.\n", 1);
	ft_putstr_fd("Your options being: ", 1);
	ft_putstr_fd("\033[0;37m\e[1mMandelbrot", 1);
	ft_putstr_fd(" \033[0;m\e[mor ", 1);
	ft_putstr_fd("\033[0;37m\e[1mSurprise", 1);
	ft_putstr_fd(" \033[0;m\e[mor ", 1);
	ft_putstr_fd("\033[0;37m\e[1mJulia [param] [param]\n", 1);
	ft_putstr_fd("If you choose the \033[0;37m\e[1mJulia \033[0;m\e[m, you have to pass 2 other arguments.\n", 1);
	ft_putstr_fd("The first is the real number, and the second is the imaginary number for the calculus of the complex number 'C'.\n", 1);
	ft_putstr_fd("REMEMBER, they can be \033[0;37m\e[1mdoubles\033[0;m\e[m.\n", 1);
	ft_putstr_fd("Enjoy :)!\n", 1);
}

int		top_right(void *param)
{
	(void)param;
	exit(0);
}

void	start_window(t_params *params, char *win_name)
{

	if (!ft_strcmp(win_name, "Surprise Set"))
	{
		win_name = "Burning";
		params->win_name = "Surprise";
	}
	params->mlx_ptr = mlx_init();
	if (!params->mlx_ptr)
	{
		ft_putstr_fd("Error initializing the Minilbx Lib.", 2);
		exit(0);
	}
	params->mlx_win = mlx_new_window(params->mlx_ptr, WIDTH, HEIGHT, win_name);
	if (!params->mlx_win)
	{
		ft_putstr_fd("Something wrong when creating the window.", 2);
		exit(0);
	}
	params->zoom = 1.0;
	if (!ft_strcmp(win_name, "Julia Set"))
		params->win_name = "Julia";
	else if (!ft_strcmp(win_name, "Mandelbrot Set"))
		params->win_name = "Mandelbrot";
	params->x_arrow = 0;
	params->y_arrow = 0;
	params->color = 1;
}
