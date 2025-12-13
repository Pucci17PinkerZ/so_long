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

int	close_window(t_game *game)
{
	free_map(game->map.map, game->map.column);
	free_img_ptr(game);
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	mlx_destroy_display(game->mlx.mlx_ptr);
	free(game->mlx.mlx_ptr);
	game->mlx.mlx_ptr = NULL;
	init_game(game);
	exit (0);
	return (0);
}

void	move_player(t_game *game, int y, int x)
{
	if (game->map.map[game->player_y + y][game->player_x + x] == '1')
	{
		game->player_mov++;
		return ;
	}
	else
	{
		if (game->map.map[game->player_y + y][game->player_x + x] == 'C')
		{
			game->map.map[game->player_y + y][game->player_x + x] = '0';
			game->map.coins_found++;
		}
		game->map.map[game->player_y][game->player_x] = '0';
		sprite_to_put(game, game->player_x, game->player_y);
		game->map.map[game->player_y + y][game->player_x + x] = 'P';
		game->player_y += y;
		game->player_x += x;
		sprite_to_put(game, game->player_x, game->player_y);
		game->player_mov++;
	}
	ft_printf("position du joueur et de map[%d][%d]\n",
		game->player_y, game->player_x);
}

int	update_movement(int keycode, t_game *game)
{
	if (keycode == KEY_S)
		move_player(game, 1, 0);
	if (keycode == KEY_W)
		move_player(game, -1, 0);
	if (keycode == KEY_A)
		move_player(game, 0, -1);
	if (keycode == KEY_D)
		move_player(game, 0, 1);
	if (keycode == KEY_ESC)
		close_window(game);
	all_coin_collected(game);
	return (0);
}

int	mlx_hookloop(t_game *game)
{
	mlx_hook(game->mlx.win_ptr, 17, 0, close_window, game);
	mlx_hook(game->mlx.win_ptr, 2, 1L << 0, update_movement, game);
	mlx_loop(game->mlx.mlx_ptr);
	return (0);
}

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

int	sprite_to_put(t_game *game, int x, int y)
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
