/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:17:42 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/18 03:29:12 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	convert_map(t_game *game, char *store_line)
{
	if ((ft_strchr(store_line, 'P') == NULL)
		|| (ft_strchr(store_line, 'E') == NULL)
		|| (ft_strchr(store_line, 'C') == NULL))
	{
		ft_putstr("Missing Minimum Element.\n");
		exit (0);
	}
	if (game->num_line - 1 == game->num_char)
	{
		ft_putstr("Not rectangle.\n");
		exit (0);
	}
	element_check(game, store_line);
	game->map_h = (game->num_line -1) * 40;
	game->map_w = game->num_char * 40;
	game->map = malloc(sizeof(char) * (game->num_line * game->num_char) + 1);
	ft_strlcpy(game->map, store_line, (game->num_line * game->num_char));
	game->fd = close(game->fd);
	free(store_line);
}

void	read_map(int byte, t_game *game, char *line, char *store_line)
{
	while (byte > 0)
	{
		game->num_line++;
		game->num_line_end = ft_strlen(line) - 1;
		if (line[0] != '1' || line[game->num_line_end] != '1')
			error_msg("Map not surronded by wall.\n");
		ft_strcat(store_line, line);
		free(line);
		line = 0;
		byte = get_next_line(game->fd, &line);
		if (byte != 0 && ft_strlen(line) != game->num_char)
			error_msg("Map nott Rectangle.\n");
		if (byte == 0)
		{
			wall_check(line);
			game->num_line++;
			ft_strcat(store_line, line);
			free(line);
			line = 0;
		}
	}
}

int	init_map(t_game *game, char *rel_path)
{
	char	*line;
	int		byte;
	char	*store_line;

	store_line = malloc(sizeof(char) * 10000);
	*store_line = 0;
	game->num_line = 0;
	game->fd = open(rel_path, O_RDONLY);
	if (game->fd == -1)
		error_msg("File can not be read.\n");
	line = 0;
	byte = get_next_line(game->fd, &line);
	wall_check(line);
	game->num_char = ft_strlen(line);
	read_map(byte, game, line, store_line);
	convert_map(game, store_line);
	return (1);
}

int	init_game(t_game *game)
{
	game->num_exit = 0;
	game->num_move = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx,
			game->map_w, game->map_h, "2D Game");
	game->mlx.mlx_img = mlx_new_image(game->mlx.mlx, game->map_w, game->map_h);
	image_init(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	argv_check(argc, argv);
	init_map(&game, argv[1]);
	init_game(&game);
	map_draw(&game);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_hook(game.mlx.mlx_win, 33, 1L << 5, exit_hook, &game);
	mlx_hook(game.mlx.mlx_win, 15, 1L << 16, reduce_window, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
