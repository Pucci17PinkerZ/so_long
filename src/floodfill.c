/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:12:35 by pucci             #+#    #+#             */
/*   Updated: 2025/11/22 18:32:15 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// int	floodfill(t_game *game, int y, int x)//retourne 1 si la map est possible sinon 0
// {
// 	if(!game)
// 		return (0);
// 	if(game->map->map[y][x] == 'E')//condition de s
// 		return (1);
// 	else
// 	{
// 		x = floodfill(game, y, x + 1);
// 		x = floodfill(game, y + 1, x);
// 		x = floodfill(game, y, x - 1);
// 		x = floodfill(game, y - 1, x);
// 		if (x == 0)
// 			return (1);
// 	}
// 	return (0);
// }