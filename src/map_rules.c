/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:42:07 by nfiora-d          #+#    #+#             */
/*   Updated: 2025/11/22 20:51:59 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	scan_item(char c, t_game *game)
{
	if(c == 'P')
		return (game->map.player_count++, 0);
	if(c == 'E')
		return (game->map.exit_count++, 0);
	if(c == 'C')
		return (game->map.coins_count++, 0);
	if(c == '0'|| c == '1')
		return (0);
	else
		return (-1);
}

int	scan_map(char c, int x,int y, t_game *game)
{
	if(y == 0 || y == game->map.column - 1)
	{
		if(c != '1')
			return (printf("JE PASSE PAR --LA CONDITION DU TOP ET DOWN\n"),-1);
	}
	else if(x == 0 || x == game->map.length - 1)
	{
		if(c != '1')
			return (printf("JE PASSE PAR --LA CONDITION DES COLONNES\n"),-1);
	}
	else
	{
		if(scan_item(c, game))
			return (printf("JE PASSE PAR --SCAN ITEM\n"),-1);
		if(game->map.map[y][x] == 'P')
			set_player(game, x, y);
	}
	if(game->map.map[y][x] == 'E')
	{
		game->hidden_door_y = y;
		game->hidden_door_x = x;
	}
	return (0);
}

int count_item(t_game *game)
{
	if(game->map.player_count != 1)
		return (-1);
	if(game->map.exit_count != 1)
		return (-1);
	if(game->map.coins_count <= 0)
		return (-1);
	return (0);
}

int	check_map(t_game *game)
{
	int y;
	int x;

	y = 0;
	
	while(y < game->map.column)
	{
		x = 0;
		while(x < game->map.length)
		{
			if(scan_map(game->map.map[y][x], x, y, game))
				return (-1);
			x++;
		}
		y++;
	}
	if (count_item(game))
		return (-1);
	return (0);
}
