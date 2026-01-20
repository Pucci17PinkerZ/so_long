/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_them.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:13:27 by pucci             #+#    #+#             */
/*   Updated: 2025/11/18 17:14:22 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int y)
{
	while (y > 0)
		free(map[--y]);
	free(map);
	return ;
}

void	free_img_ptr(t_game *game)
{
	if (game->sprite.img_coin)
		mlx_destroy_image(game->mlx.mlx_ptr, game->sprite.img_coin);
	if (game->sprite.img_exit)
		mlx_destroy_image(game->mlx.mlx_ptr, game->sprite.img_exit);
	if (game->sprite.img_floor)
		mlx_destroy_image(game->mlx.mlx_ptr, game->sprite.img_floor);
	if (game->sprite.img_wall)
		mlx_destroy_image(game->mlx.mlx_ptr, game->sprite.img_wall);
	if (game->sprite.img_player)
		mlx_destroy_image(game->mlx.mlx_ptr, game->sprite.img_player);
	return ;
}
