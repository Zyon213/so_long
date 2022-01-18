/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 02:52:27 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/18 02:32:32 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_element(t_game *game)
{
	game->s = 0;
	game->w = 0;
	game->c = 0;
	game->e = 0;
	game->p = 0;
}

void	argv_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Invalid number of argument.\n");
		exit (0);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strchr(argv[1], '.')))
	{
		ft_putstr("Invalid argument.\n");
		exit (0);
	}
	if (ft_strcmp(ft_strchr(argv[1], '.'), ".ber") != 0)
	{
		ft_putstr("Invalid file type.\n");
		exit (0);
	}
}

void	element_check(t_game *game, char *whole_map)
{
	int	i;

	i = 0;
	init_element(game);
	while (whole_map[i])
	{
		if (whole_map[i] != '0' && whole_map[i] != '1'
			&& whole_map[i] != 'C' && whole_map[i] != 'E'
			&& whole_map[i] != 'P')
		{
			ft_putstr("Invalid map element.\n");
			exit (1);
		}
		i++;
		game->e++;
		game->c++;
		game->p++;
	}
	if (game->e == 0 || game->c == 0 || game->p == 0)
	{
		ft_putstr("Map missing element.\n");
		exit (0);
	}
}

void	wall_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
		{
			ft_putstr("Map not surrouded by wall.\n");
			free(line);
			exit (0);
		}
		i++;
	}
}

void	error_msg(char *msg)
{
	ft_putstr("Error!\n");
	ft_putstr(msg);
	exit (0);
}
