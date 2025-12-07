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
#define SO_LONG_H

#define KEY_W 119
#define KEY_S 97
#define KEY_A 115
#define KEY_D 100

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
// # include "../printf/ft_printf.h"


typedef struct s_map
{
	char	**map;
	int		length;
	int		column;
	int		coins_count;
	int		player_count;
	int		exit_count;


} t_map;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
} t_mlx;

typedef struct s_sprite
{
	void	*img_wall;
	void	*img_floor;
	void	*img_coin;
	void	*img_player;
	void	*img_exit;
	int		img_width;
	int		img_height;
} t_sprite;

typedef struct s_game
{
	const char *filename;
	t_sprite	sprite;
	t_map	map;
	t_mlx	mlx;
	int player_x;
	int player_y;
	long player_mov;
	int key_pressed[256];
} t_game;

int *read_map(const char *filename, t_game *game);

//pour new_map
int	new_map(t_game *game);
char	**malloc_map(const char *filename, int x, int column, char **map);
int	check_column(const char *filename);
int	check_length(const char *filename);

//pour set le jeu
void	init_game(t_game *game);
void	init_sprite(t_sprite *sprite);
void	init_mlx(t_mlx *mlx);
void	init_map(t_map *map);
void	set_player(t_game * game, int x, int y);

//pour les check de map
int	scan_item(char c, t_game *game);
int	scan_map(char c, int x,int y, t_game *game);
int count_item(t_game *game);
int	check_map(t_game *game);
int	floodfill(t_game *game, int y, int x);

//pour la fenetre
int	load_sprite(t_game *game);
int mlx_windows_start(t_game *game);
int	mlx_hookloop(t_game *game);
int	close_window(t_game *game);
int	put_img(t_game *game);
int sprite_to_put(t_game *game, int x , int y);

//pour set les valeurs
void set_game(t_game *game, char *filename);

//pour les leaks
void	free_map(char **map, int y);
void	set_free(t_game *game);

#endif