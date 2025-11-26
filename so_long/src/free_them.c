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
}

void set_free(t_game *game)
{
	free(game->map);
	free(game->mlx);
	free(game->sprite);
}