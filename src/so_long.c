/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci_pinker <pucci_pinker@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:25:50 by pucci             #+#    #+#             */
/*   Updated: 2025/12/10 14:55:43 by pucci_pinke      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
	{
		printf("utilisation---->  ./so_long <map.ber>\n");
		return (0);
	}
	init_game(&game);
	game.sprite.img_height = 64;
	game.sprite.img_width = 64;
	game.filename = argv[1];
	if (new_map(&game))
		return (printf("map pas ok\n"), 1);
	if (check_map(&game))
	{
		printf("la map pas ok:'(\n");
		return (0);
	}
	copy_map(&game);
	if (floodfill(&game, game.player_y, game.player_x))
		return (printf("impossible de finir\n"), 2);
	printf("\nla map jouable :)\n");
	mlx_windows_start(&game);
	return (0);
}
