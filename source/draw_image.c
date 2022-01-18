/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:36:15 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/18 02:14:39 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_box(t_game *game, t_img *img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(255, 0, 0, 0))
				mlx_draw_pixel(game->mlx.mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	map_check(t_game *game, int x, int y, int z)
{
	if (game->map[z + game->num] == 'P')
		draw_box(game, game->player, x, y * 39);
	if (game->map[z + game->num] == 'C')
		draw_box(game, game->collect, x, y * 39);
	if (game->map[z + game->num] == 'E' || game->map[z + game->num] == 'X')
		draw_box(game, game->exit, x, y * 39);
}

void	map_draw(t_game *game)
{
	int	z;

	game->num = 0;
	game->y = 0;
	game->x = -40;
	while (game->y < (game->num_line - 1))
	{
		z = 0;
		while (z < game->num_char)
		{
			if (game->map[z + game->num] == '1')
				draw_box(game, game->wall, game->x += 40, game->y * 39);
			else
			{
				draw_box(game, game->floor, game->x += 40, game->y * 39);
				map_check(game, game->x, game->y, z);
			}
			z++;
		}
		game->y++;
		game->num = game->num_char * game->y;
	}
	mlx_put_image_to_window(game->mlx.mlx,
		game->mlx.mlx_win, game->mlx.mlx_img, 0, 0);
}
