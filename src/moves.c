/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:03:00 by yoyohann          #+#    #+#             */
/*   Updated: 2022/02/23 17:15:49 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_game_exit(t_game game)
{
	if (game.map[game.ply_pos.y][game.ply_pos.x] == 'e')
		exit (0);
}

void	ft_redraw_map(t_game *game)
{
	int	i;
	int	j;
	static int m = 1;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->map[i][j] = '0';
			if (i == game->ply_pos.y && j == game->ply_pos.x)
			{
				game->map[i][j] = 'P';
				ft_putnbr(m++);
				ft_putchar('\n');
			}
			if (game->c == 0 && game->map[i][j] == 'E')
				game->map[i][j] = 'e';
			ft_game_exit(*game);			
			j++;
		}
		i++;
	}
}

void	ft_move_dir(int keycode, t_game *game)
{
	if (keycode == 13)
		game->ply_pos.y -= 1;
	if (keycode == 1)
		game->ply_pos.y += 1;
	if (keycode == 0)
	{
		game->ply_pos.x -= 1;
		game->dir = "left";
	}
	if (keycode == 2)
	{
		game->ply_pos.x += 1;
		game->dir = "right";
	}
}

int	ft_game_play(int keycode, t_game *game)
{
	game->m = 0;
	if (keycode == 53)
		exit (0);
	ft_move_dir(keycode, game);
	if (game->map[game->ply_pos.y][game->ply_pos.x] != '1'
		&& game->map[game->ply_pos.y][game->ply_pos.x] != 'E')
		ft_redraw_map(game);
	ft_map(game->map, game);
	return (0);
}
