/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemiguel <pemiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:33:43 by pemiguel          #+#    #+#             */
/*   Updated: 2023/02/09 23:31:40 by pemiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//bibliotecas necessárias
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

//o ponto pertence à base pois os numéros passados vao ser floats
# define DEC_BASE "0123456789.-"
# define SURPRISE "Surprise"
# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"

# define HEIGHT 800
# define WIDTH 800
# define MAX_ITERATIONS 150

# define PLUS 65451
# define MINUS 65453

# define ESC 65307
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363
# define ARROW_UP 65362
# define ARROW_LEFT 65361

//complex number = real_number + imaginary_number
typedef struct	complex
{
    double  r; //real
    double  i; //imaginário
}		complex;


typedef struct s_params {
	void	*mlx_ptr;
	void	*mlx_win;
	double	zoom;
	void	*img;
	char	*addr;
	int		bits;
	int		line_length;
	int		endian;
	char	*win_name;
	double	real_c;
	double	imaginary_c;
	int		x_arrow;
	int		y_arrow;
	int		color;
}		t_params;

//utils
int		ft_atoi(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);

//utils2
int		ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
double	ft_atof(const char *str);

//basics
void	start_window(t_params *params, char *win_name);
void	requirements(void);
int		top_right(void *param);

//draw
void	draw_julia(t_params *params);
void	draw_mandelbrot(t_params *params);
void	draw_surprise(t_params *params);

//hooks
int		mouse_zoom(int key, int x, int y, t_params *param);
int		keys_pressed(int key, t_params *params);

//img
void	start_image(t_params *params);
void	my_mlx_pixel_put(t_params *img, int x, int y, int iterations);

#endif
