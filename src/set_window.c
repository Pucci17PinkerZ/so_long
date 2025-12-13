/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci_pinker <pucci_pinker@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:57:15 by pucci             #+#    #+#             */
/*   Updated: 2025/12/10 15:08:13 by pucci_pinke      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_sprite(t_game *game)
{
	game->sprite.img_player = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/player1.xpm", &game->sprite.img_width,
			&game->sprite.img_height);
	game->sprite.img_wall = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/wall1.xpm", &game->sprite.img_width,
			&game->sprite.img_height);
	game->sprite.img_floor = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/floor1.xpm", &game->sprite.img_width,
			&game->sprite.img_height);
	game->sprite.img_coin = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/coin1.xpm", &game->sprite.img_width,
			&game->sprite.img_height);
	game->sprite.img_exit = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			"assets/exit1.xpm", &game->sprite.img_width,
			&game->sprite.img_height);
	return (0);
}

void	sprite_to_put(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr,
			game->mlx.win_ptr, game->sprite.img_floor, x * 128, y * 128);
	}
	if (game->map.map[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr,
			game->mlx.win_ptr, game->sprite.img_wall, x * 128, y * 128);
	}
	sprite_to_put_two(game, x, y);
	return ;
}

void	sprite_to_put_two(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr,
			game->mlx.win_ptr, game->sprite.img_player, x * 128, y * 128);
	}
	if (game->map.map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr,
			game->mlx.win_ptr, game->sprite.img_floor, x * 128, y * 128);
	}
	if (game->map.map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr,
			game->mlx.win_ptr, game->sprite.img_coin, x * 128, y * 128);
	}
	return ;
}

int	put_img(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.column)
	{
		x = 0;
		while (x < game->map.length)
		{
			sprite_to_put(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	mlx_windows_start(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		return (perror("mlx_init"), 1);
	game->mlx.win_width = game->map.length * 128;
	game->mlx.win_height = game->map.column * 128;
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr, game->mlx.win_width,
			game->mlx.win_height, "so_long");
	if (!game->mlx.win_ptr)
		return (perror("mlx_new_window"), 1);
	load_sprite(game);
	put_img(game);
	mlx_hookloop(game);
	return (0);
}
