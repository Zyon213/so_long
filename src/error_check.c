/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:51:05 by yoyohann          #+#    #+#             */
/*   Updated: 2022/02/23 15:57:08 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_item_count(char **map)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	i = -1;
	c = 0;
	e = 0;
	p = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'E')
				e++;
		}
	}
	if (p == 0 || c == 0 || e == 0)
		error_msg("Missing minimum number of items.\n");
}

void	ft_is_items_valid(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != '0'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				error_msg("Invalid Item.\n");
		}
	}
	ft_item_count(map);
}

void	ft_is_top_bot_wall_valid(char **map, int h)
{
	int	i;
	int	j;

	i = 0;
	while (i <= h - 1)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1')
				error_msg("Map not surronded by wall.\n");
		}
		i += h - 1;
	}
}

void	ft_is_wall_valid(char **map, int l, int h)
{
	int	i;

	i = 0;
	ft_is_top_bot_wall_valid(map, h);
	while (++i < h - 1)
	{
		if (map[i][0] != '1' || map[i][l - 1] != '1')
			error_msg("Map not surronded by wall.\n");
	}
}

void	ft_is_map_valid(char **map)
{
	int	l;
	int	h;
	int	i;

	i = 0;
	h = 0;
	if (map == NULL)
		error_msg("Empty file.\n");
	l = ft_strlen(map[i]);
	while (map[h])
		h++;
	while (map[i])
	{
		if (l != ft_strlen(map[i]))
			error_msg("Map is not rectangle.\n");
		i++;
	}
	ft_is_wall_valid(map, l, h);
	ft_is_items_valid(map);
}	
