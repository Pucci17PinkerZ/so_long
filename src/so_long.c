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
		ft_printf("use it that way---->  ./so_long <map.ber>\n");
		return (0);
	}
	init_game(&game);
	game.filename = argv[1];
	if (new_map(&game) || check_ber(&game))
		return (ft_printf("map not ok\n"), 1);
	if (check_gameplay(&game))
		return (1);
	ft_printf("\nmap is playable :)\n");
	if (mlx_windows_start(&game))
	{
		free_map(game.map.map, game.map.column);
		return (1);
	}
	return (0);
}

int	check_ber(t_game *game)
{
	int	i;

	i = strlen(game->filename);
	if (i < 3)
		return (1);
	printf("\n---%s----\n",&game->filename[i - 4]);
	if (ft_strncmp(&game->filename[i - 4], ".ber", 4))
		return (ft_printf(".ber pls\n"), 1);
	return (0);
}

int	check_gameplay(t_game *game)
{
	if (check_map(game))
	{
		ft_printf("map not ok :(\n");
		return (free_map(game->map.map, game->map.column), 1);
	}
	if (copy_map(game) || floodfill(game, game->player_y, game->player_x))
	{
		free_map(game->map.copy_map, game->map.column);
		free_map(game->map.map, game->map.column);
		init_game(game);
		return (ft_printf("end impossible\n"), 1);
	}
	free_map(game->map.copy_map, game->map.column);
	game->map.copy_map = NULL;
	return (0);
}
