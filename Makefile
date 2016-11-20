# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 16:05:38 by vcaquant          #+#    #+#              #
#    Updated: 2016/11/15 16:05:40 by vcaquant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			fractol

SRC = 			sources/fractol.c \
				sources/fractal.c \
				sources/ft_mandelbrot.c \
				sources/ft_julia.c \
				sources/ft_burningship.c \
				sources/ft_put_pixel.c \
				sources/ft_code.c \
				sources/ft_variation.c \
				sources/ft_help.c \
				sources/ft_menu.c

OBJ = 			fractol.o \
				fractal.o \
				ft_mandelbrot.o \
				ft_julia.o \
				ft_burningship.o \
				ft_put_pixel.o \
				ft_code.o \
				ft_variation.o \
				ft_help.o \
				ft_menu.o

HEADER =		./libft/libft.h \

FINDLIBFT =		-Llibft

PT_A =			./minilibx_macos\ sierra/libmlx.a \
			./libft/libft.a

FLAGS = 		-Wall -Wextra -Werror -g

LIBX_FS =		-framework OpenGL -framework AppKit

LIBFT_DIR =		./libft/

LIBX_DIR =		./minilibx_macos\ sierra/

CC = 			gcc

all:	comp_oth $(NAME)

comp_oth:
		@make fclean -C $(LIBFT_DIR)
		@make -C $(LIBFT_DIR)
		@make -C $(LIBX_DIR)

$(NAME):
		@clear
		@$(CC) $(FLAGS) -c $(SRC) $(HEADER)
		@$(CC) -o $(NAME) $(OBJ) $(PT_A) $(LIBX_FS)
		@echo "\033[0;32m✔︎ Compilation Done\033[0m"

clean:
		@clear
		@rm -f $(OBJ)
		@rm -f fdf.h.gch
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(LIBX_DIR)
		@echo "\033[0;31m✔︎ Cleaning Done\033[0m"

fclean:	clean
		@clear
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_DIR)
		@echo "\033[0;31m✔︎ Fcleaning Done\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
