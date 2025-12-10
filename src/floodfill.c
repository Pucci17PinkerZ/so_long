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

// #include "so_long.h"
// int	floodfill(t_game *game, int y, int x)
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