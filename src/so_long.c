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
	new_map(&game);
	if (check_map(&game))
	{
		printf("la map ne remplit pas les conditions :'(\n");
		return (0);
	}
	copy_map(&game);
	if (floodfill(&game, game.player_y, game.player_x))
		return (printf("la map n'est pas réalisable\n"), 2);
	printf("\nla map remplit toutes les conditions :)\n");
	mlx_windows_start(&game);
}
