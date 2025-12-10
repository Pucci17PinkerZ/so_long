/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:57:38 by pucci             #+#    #+#             */
/*   Updated: 2025/11/26 15:57:39 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	init_game(t_game *game)
{
	if (!game)
		return;
	game->filename = NULL;
	init_sprite(&game->sprite);
	init_map(&game->map);
	init_mlx(&game->mlx);
	game->player_y = 0;
	game->player_x = 0;
	ft_bzero(game->key_pressed, sizeof(game->key_pressed));
	game->keycode = 0;
	game->hidden_door_x = 0;
	game->hidden_door_y = 0;
}

void	init_sprite(t_sprite *sprite)
{
	if (!sprite)
		return;
	sprite->img_wall = NULL;
	sprite->img_floor = NULL;
	sprite->img_coin = NULL;
	sprite->img_player = NULL;
	sprite->img_exit = NULL;
	sprite->img_width = 0;
	sprite->img_height = 0;
}

void	init_mlx(t_mlx *mlx)
{
	if (!mlx)
		return;
	
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->win_width = 0;
	mlx->win_height = 0;
}

void	init_map(t_map *map)
{
	if (!map)
		return;
	map->map = NULL;
	map->length = 0;
	map->column = 0;
	map->coins_count = 0; 
	map->player_count = 0;
	map->exit_count = 0;
	map->coins_found = 0;
}

void	set_player(t_game * game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	game->player_mov = 0;
}