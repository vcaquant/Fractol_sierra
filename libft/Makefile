# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 03:44:14 by vcaquant          #+#    #+#              #
#    Updated: 2016/05/12 15:09:13 by vcaquant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = ft_atoi.c \
		   ft_strrchr.c \
		   ft_bzero.c \
		   ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_isprint.c \
		   ft_memccpy.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memset.c \
		   ft_memmove.c \
		   ft_memcpy.c \
		   ft_putchar.c \
		   ft_putchar_fd.c \
		   ft_putstr.c \
		   ft_putstr_fd.c \
		   ft_strcat.c \
		   ft_strchr.c \
		   ft_strcmp.c \
		   ft_strcpy.c \
		   ft_strdup.c \
		   ft_strlcat.c \
		   ft_strlen.c \
		   ft_strclen.c \
		   ft_strncat.c \
		   ft_strncmp.c \
		   ft_strncpy.c \
		   ft_strnstr.c \
		   ft_strstr.c \
		   ft_tolower.c \
		   ft_toupper.c \
		   ft_putendl.c \
		   ft_putendl_fd.c \
		   ft_putnbr.c \
		   ft_putnbr_fd.c \
		   ft_itoa.c \
		   ft_memalloc.c \
		   ft_memdel.c \
		   ft_strclr.c \
		   ft_strdel.c \
		   ft_strequ.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strjoin.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strnequ.c \
		   ft_strnew.c \
		   ft_strsplit.c \
		   ft_strsub.c \
		   ft_strtrim.c \
		   ft_strnncpy.c \
		   get_next_line.c \

OBJ_PATH = ./

INC_PATH = ./

LIB_PATH = ./

NAME = libft.a

CC = clang

CFLAGS = -Werror -Wall -Wextra -c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -I $(INC) 
	@ar rc $(NAME) $(OBJ_NAME)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJ_NAME)

fclean: clean
	@/bin/rm -rf $(NAME)

re: clean fclean all

.PHONY: all, clean, fclean, re
