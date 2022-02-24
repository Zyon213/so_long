/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:22:33 by yoyohann          #+#    #+#             */
/*   Updated: 2022/02/23 16:26:24 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"

typedef struct t_dim
{
	int	x;
	int	y;
}	t_dim;

typedef struct t_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_dim	win_size;
	t_dim	ply_pos;
	int		c;
	char	*dir;
	int		m;
}	t_game;

char	**ft_create_map(char *file_name);
void	ft_argv_check(int argc, char **argv);
void	error_msg(char *msg);
int		ft_game_play(int keycode, t_game *game);
void	ft_move_dir(int keycode, t_game *game);
void	ft_map(char **map_name, t_game *game);
void	ft_draw_box(char sign, t_game *game, int i, int j);
void	ft_box(char *path, t_game game);
void	ft_game_exit(t_game game);
void	ft_item_count(char **map);
void	ft_is_items_valid(char **map);
void	ft_is_top_bot_wall_valid(char **map, int h);
void	ft_is_wall_valid(char **map, int l, int h);
void	ft_is_map_valid(char **map);
void	ft_displaynum(int n);
//void	ft_ply_move(t_game game);

#endif
