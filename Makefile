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
MLXD = mlx/
MLX = libmlx.a 
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f
EFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

FILES = src/so_long.c src/error_check.c \
		utils/get_next_line.c utils/gnl_utils.c \
		utils/libft_utils.c src/moves.c src/draw_map.c \
		utils/ft_split.c src/arg_error.c

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@		

all : $(NAME)

$(NAME): $(OBJ)
	@cd $(MLXD) && make
	@cp $(MLXD)$(MLX) .
	$(CC) $(CFLAGS) $(EFLAGS) $(FILES) -o $(NAME)

clean:
	cd $(MLXD) && make clean
	$(RM) $(MLX)
	$(RM) *.o 

fclean: clean
	$(RM) $(NAME)

re: clean all