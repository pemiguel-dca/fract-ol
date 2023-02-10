#-*- Makefile -*-

#target : dependencies
#       action

CFLAGS = -march=native -Wall -Werror -Wextra -g -I.

NAME = fractol

UTILS = utils.c utils2.c basics.c draw.c img.c hooks.c keys.c bonus_fractal.c main.c
OBJ_UTILS = $(UTILS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_UTILS)
		cc $(CFLAGS) $(OBJ_UTILS) -lbsd -lmlx -lXext -lX11 -lm -o $(NAME)
		@printf [SUCCESS]"Program was created successfully!\n"

clean:
		rm -rf $(OBJ_UTILS)

fclean: clean
		rm -f $(NAME)

re : fclean all
