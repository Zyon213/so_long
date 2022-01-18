# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 11:26:00 by yoyohann          #+#    #+#              #
#    Updated: 2021/10/11 20:38:34 by yonas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
EFLAGS =  -L ../libft -lmlx -lXext -lX11

FILES = source/draw_image.c \
		source/error_check.c \
		source/load_image.c \
		source/so_long.c \
		source/hooks.c \
		source/move.c \
		gnl/get_next_line.c 

all : $(NAME)

$(NAME):
	cd mlx/ && ./configure
	$(CC) $(CFLAGS) $(FILES) $(EFLAGS) -o $(NAME) $(LIB)

clean:
	$(RM) *.o 

fclean: clean
	$(RM) $(NAME)

re: clean all