/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:17:42 by yoyohann          #+#    #+#             */
/*   Updated: 2022/02/23 16:18:55 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_close(int keycode)
{
	(void)keycode;
	exit (0);
}

char	**ft_create_map(char *file_name)
{
	char	**map;
	char	*line;
	char	*next_line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	line = ft_get_next_line(fd);
	next_line = ft_get_next_line(fd);
	while (next_line)
	{
		line = ft_strjoin(line, next_line);
		next_line = ft_get_next_line(fd);
	}
	map = ft_split(line, '\n');
	return (map);
}

void	ft_window_size(char *file_name, t_dim *win_size)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = ft_get_next_line(fd);
	win_size->x = ft_strlen(line) - 1;
	win_size->y = 0;
	while (line)
	{
		win_size->y++;
		line = ft_get_next_line(fd);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_dim	win_dim;

	game.m = 0;
	ft_argv_check(argc, argv);
	game.map = ft_create_map(argv[1]);
	ft_is_map_valid(game.map);
	ft_window_size(argv[1], &win_dim);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, win_dim.x * 40,
			win_dim.y * 40, "2D Game");
	mlx_hook(game.mlx_win, 17, 0, ft_close, &game);
	ft_map(game.map, &game);
	mlx_key_hook(game.mlx_win, ft_game_play, &game);
	mlx_loop(game.mlx);
	return (0);
}
