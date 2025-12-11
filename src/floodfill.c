/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci_pinker <pucci_pinker@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:12:35 by pucci             #+#    #+#             */
/*   Updated: 2025/12/10 15:04:17 by pucci_pinke      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	floodfill(t_game *game, int y, int x)
{
	if (game->map.copy_map[y][x] == '1' || game->map.copy_map[y][x] == 'V')
		return (1);
	else if (game->map.copy_map[y][x] == 'C')
	{
		game->map.copy_map[y][x] = 'V';
		game->map.coins_found_two++;
	}
	else if (game->map.copy_map[y][x] == 'E')
	{
		game->map.exit_found++;
		game->map.copy_map[y][x] = 'V';
		return (1);
	}
	else if (game->map.copy_map[y][x] == '0')
		game->map.copy_map[y][x] = 'V';
	floodfill(game, y, x + 1);
	floodfill(game, y + 1, x);
	floodfill(game, y, x - 1);
	floodfill(game, y - 1, x);
	if (game->map.coins_found_two == game->map.coins_count
	&& game->map.exit_count)
			return (0);
	return (1);
}

int	copy_map(t_game *game)
{
	int	i;

	i = 0;
	game->map.copy_map = malloc(sizeof(char *) * (game->map.column + 1));
	if (!game->map.copy_map)
		return (1);
	while (i < game->map.column)
	{
		game->map.copy_map[i] = ft_strdup(game->map.map[i]);
		if (!game->map.copy_map[i])
		{
			free_map(game->map.copy_map, i);
			free_map(game->map.map, i);
			return (1);
		}
		i++;
	}
	game->map.copy_map[i] = NULL;
	return (0);
}
