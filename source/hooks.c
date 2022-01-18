/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:36:32 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/18 02:39:45 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	mlx_destroy_display(game->mlx.mlx);
	exit (0);
}

int	reduce_window(t_game *game)
{
	map_draw(game);
	return (1);
}

void	check_game(t_game *game)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (ft_strchr(game->map, 'E') == NULL)
	{
		if (game->num_exit <= 1)
			if (ft_strchr(game->map, 'X') == NULL)
				exit_hook(game);
		while (game->map[i])
		{
			if (game->map[i] == 'X')
				count++;
			i++;
		}
		if (count == game->num_exit -1)
			exit_hook(game);
	}
}

int	key_hook(int keysym, t_game *game)
{
	if (ft_strchr(game->map, 'C') == NULL)
	{
		while (ft_strchr(game->map, 'E'))
		{
			game->num_exit++;
			*ft_strchr(game->map, 'E') = 'X';
		}
	}
	if (keysym == XK_Escape)
		exit_hook(game);
	if (keysym == XK_s)
		move_down(game);
	if (keysym == XK_w)
		move_up(game);
	if (keysym == XK_a)
		move_right(game);
	if (keysym == XK_d)
		move_left(game);
	check_game(game);
	map_draw(game);
	return (1);
}
