/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:36:44 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/18 02:51:46 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_image(t_game *game, t_img **img, char *rel_path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx.mlx, rel_path, &width, &height);
	if (*img == 0)
	{
		ft_putstr("Can't load image.");
		exit (0);
	}
	(*img)->width = width;
	(*img)->height = height;
}

void	image_init(t_game *game)
{
	load_image(game, &game->floor, "./img/floor.xpm");
	load_image(game, &game->player, "./img/player.xpm");
	load_image(game, &game->collect, "./img/collect.xpm");
	load_image(game, &game->wall, "./img/wall.xpm");
	load_image(game, &game->exit, "./img/exit.xpm");
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->data
		+ (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char	*dst;

	dst = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)dst = color;
}

unsigned int	mlx_rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
