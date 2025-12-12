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
	game.filename = argv[1];
	if (new_map(&game))
		return (printf("map pas ok\n"), 1);
	if (check_map(&game))
	{
		printf("la map pas ok :(\n");
		return (free_map(game.map.map, game.map.column), 1);
	}
	if (copy_map(&game))
		return (1);
	if (floodfill(&game, game.player_y, game.player_x))
	{
		free_map(game.map.copy_map, game.map.column);
		free_map(game.map.map, game.map.column);
		return (printf("impossible de finir\n"), 2);
	}
	printf("\nla map est jouable :)\n");
	
	if (mlx_windows_start(&game))
	{
		free_map(game.map.map, game.map.column);
		return (1);
	}
		
	return (0);
}
