/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci_pinker <pucci_pinker@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:01:26 by pucci_pinke       #+#    #+#             */
/*   Updated: 2025/12/10 16:07:52 by pucci_pinke      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	all_coin_collected(t_game *game)
{
	if (game->map.coins_count == game->map.coins_found)
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr,
			game->mlx.win_ptr, game->sprite.img_exit, game->hidden_door_x * 128,
			game->hidden_door_y * 128);
	}
	if (game->map.coins_count == game->map.coins_found
		&& game->hidden_door_y == game->player_y
		&& game->hidden_door_x == game->player_x)
	{
		printf("you won!\n");
		close_window(game);
		printf("valeur du pointeur");
		exit (0);
	}
}
