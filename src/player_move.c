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
	ft_printf("on map[%d][%d]\nmoves == %d\n",
		game->player_y, game->player_x,game->player_mov);
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
