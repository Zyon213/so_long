/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:36:51 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/18 03:04:29 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_down(t_game *game)
{
	char	*c;
	int		i;

	c = ft_strchr(game->map, 'P');
	i = -1;
	while (++i < game->num_char)
		++c;
	if (*c != '1' && *c != 'E')
	{
		*c = 'P';
		c = ft_strchr(game->map, 'P');
		*c = '0';
		game->num_move += 1;
		ft_putnbr(game->num_move);
		ft_putchar('\n');
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	load_image(game, &game->player, "./img/player.xpm");
}

void	move_up(t_game *game)
{
	char	*c;
	int		i;

	c = ft_strchr(game->map, 'P');
	i = -1;
	while (++i < game->num_char)
		--c;
	if (*c != '1' && *c != 'E')
	{
		*c = 'P';
		while (--i >= 0)
			++c;
		*c = '0';
		game->num_move += 1;
		ft_putnbr(game->num_move);
		ft_putchar('\n');
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	load_image(game, &game->player, "./img/player.xpm");
}

void	move_left(t_game *game)
{
	char	*c;

	c = ft_strchr(game->map, 'P');
	if (*++c != '1' && *c != 'E')
	{
		*--c = '0';
		*++c = 'P';
		game->num_move += 1;
		ft_putnbr(game->num_move);
		ft_putchar('\n');
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	load_image(game, &game->player, "./img/player.xpm");
}

void	move_right(t_game *game)
{
	char	*c;

	c = ft_strchr(game->map, 'P');
	if (*--c != '1' && *c != 'E')
	{
		*++c = '0';
		*--c = 'P';
		game->num_move += 1;
		ft_putnbr(game->num_move);
		ft_putchar('\n');
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	load_image(game, &game->player, "./img/player.xpm");
}
