/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:57:27 by pucci             #+#    #+#             */
/*   Updated: 2025/11/26 17:43:35 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_map
{
	char	**map;
	int		length;
	int		column;
	int		coins_count;
	int		player_count;
	int		exit_count;
	int		coins_found;
	char	**copy_map;
	int		coins_found_two;
	int		exit_found;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
}	t_mlx;

typedef struct s_sprite
{
	void	*img_wall;
	void	*img_floor;
	void	*img_coin;
	void	*img_player;
	void	*img_exit;
	int		img_width;
	int		img_height;
}	t_sprite;

typedef struct s_game
{
	const char	*filename;
	t_sprite	sprite;
	t_map		map;
	t_mlx		mlx;
	int			player_x;
	int			player_y;
	long		player_mov;
	int			key_pressed[256];
	int			keycode;
	int			hidden_door_y;
	int			hidden_door_x;
}	t_game;

int		check_gameplay(t_game *game);
int		*read_map(const char *filename, t_game *game);
int		new_map(t_game *game);
int		check_ber(t_game *game);
char	**malloc_map(t_game *game, int column);
int		malloc_map_two(t_game *game, int y, int fd);
int		check_column(const char *filename);
int		check_length(const char *filename);
void	init_game(t_game *game);
void	init_sprite(t_sprite *sprite);
void	init_mlx(t_mlx *mlx);
void	init_map(t_map *map);
void	set_player(t_game *game, int x, int y);
int		scan_item(char c, t_game *game);
int		scan_map(char c, int x, int y, t_game *game);
int		count_item(t_game *game);
int		check_map(t_game *game);
int		floodfill(t_game *game, int y, int x);
int		copy_map(t_game *game);
int		load_sprite(t_game *game);
int		mlx_windows_start(t_game *game);
int		mlx_hookloop(t_game *game);
int		close_window(t_game *game);
int		put_img(t_game *game);
void	sprite_to_put(t_game *game, int x, int y);
void	sprite_to_put_two(t_game *game, int x, int y);
void	set_game(t_game *game, char *filename);
void	free_map(char **map, int y);
void	set_free(t_game *game);
void	all_coin_collected(t_game *game);
void	free_img_ptr(t_game *game);

#endif