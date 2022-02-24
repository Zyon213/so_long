/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:37:29 by yoyohann          #+#    #+#             */
/*   Updated: 2022/02/23 15:50:25 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_box(char *path, t_game game)
{
	void	*dst;
	int		x;
	int		y;

	x = 0;
	y = 0;
	dst = mlx_xpm_file_to_image(game.mlx, path, &x, &y);
	mlx_put_image_to_window(game.mlx, game.mlx_win, dst,
		   	game.win_size.x, game.win_size.y);
}
/*
void	ft_ply_move(t_game game)
{
	if (game.dir[0] == 'r')
		ft_box("./img/fhead.xpm", game);
	else if (game.dir[0] == 'l')
		ft_box("./img/bhead.xpm", game);
}
*/
void	ft_draw_box(char sign, t_game *game, int i, int j)
{
	if (sign == '1')
		ft_box("./img/wall.xpm", *game);
	else if (sign == '0')
		ft_box("./img/floor.xpm", *game);
	else if (sign == 'C')
	{
		ft_box("./img/collect.xpm", *game);
		game->c += 1;
	}
	else if (sign == 'E')
		ft_box("./img/exit.xpm", *game);
	else if (sign == 'P')
	{
		ft_box("./img/player.xpm", *game);
		game->ply_pos.x = j;
		game->ply_pos.y = i;
	//	ft_ply_move(*game);	
	}
}

void	ft_map(char **map_name, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->win_size.y = 0;
	game->c = 0;
	while (map_name[i])
	{
		game->win_size.x = 0;
		j = 0;
		while (map_name[i][j])
		{
			ft_draw_box(map_name[i][j], game, i, j);
			j++;
			game->win_size.x += 40;
		}
		game->win_size.y += 40;
		i++;
	}
}
