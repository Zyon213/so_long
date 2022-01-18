/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 04:15:35 by yoyohann          #+#    #+#             */
/*   Updated: 2022/01/15 04:15:38 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "../mlx/mlx_int.h"
# include "get_next_line.h"
# include <string.h>

typedef struct t_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	*mlx_img;
}			t_mlx;

typedef struct t_game
{
	t_mlx	mlx;
	int		map_w;
	int		map_h;
	int		num;
	int		num_move;
	int		num_exit;
	int		num_line;
	int		num_line_end;
	int		num_char;
	t_img	*floor;
	t_img	*player;
	t_img	*collect;
	t_img	*wall;
	t_img	*exit;
	char	*map;
	int		fd;
	int		x;
	int		y;
	char	*player_pos;
	int		s;
	int		w;
	int		c;
	int		e;
	int		p;
}			t_game;

unsigned int	mlx_get_pixel(t_img *img, int x, int y);
unsigned int	mlx_rgb_to_int(int t, int r, int g, int b);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
unsigned int	mlx_rgb_to_int(int t, int r, int g, int b);
void			argv_check(int argc, char **argv);
void			wall_check(char *line);
void			element_check(t_game *game, char *whole_map);
void			argv_check(int argc, char **argv);
void			load_image(t_game *game, t_img **img, char *rel_path);
void			image_init(t_game *game);
void			map_draw(t_game *game);
void			map_check(t_game *game, int x, int y, int z);
void			draw_box(t_game *game, t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
void			read_map(int byte, t_game *game, char *line, char *store_line);
void			convert_map(t_game *game, char *store_line);
void			move_down(t_game *game);
void			move_up(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			error_msg(char *msg);
void			check_game(t_game *game);
int				reduce_window(t_game *game);
int				init_map(t_game *game, char *rel_path);
int				init_game(t_game *game);
int				exit_hook(t_game *game);
int				key_hook(int keysym, t_game *game);

#endif