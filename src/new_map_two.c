/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci_pinker <pucci_pinker@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:36:36 by pucci             #+#    #+#             */
/*   Updated: 2025/12/10 14:57:26 by pucci_pinke      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	malloc_map_two(t_game *game, char **map, int y, int fd)
{
	int		i;
	char	*ref_line;

	i = 0;
	ref_line = get_next_line(fd);
	if (game->map.column - 1 == y && ref_line[game->map.length] == '\n')
		return (close(fd), free(ref_line), 1);
	if (!ref_line)
		return (1);
	i = 0;
	while (ref_line[i] && ref_line[i] != '\n')
		i++;
	if (i != game->map.length)
		return (free(ref_line), ft_printf("map freed\n"),
			close(fd), 1);
	map[y] = ft_substr(ref_line, 0, game->map.length);
	free(ref_line);
	return (0);
}

char	**malloc_map(t_game *game, int column, char **map)
{
	int		y;
	int		fd;

	y = 0;
	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		return (free(map), NULL);
	if (!map)
		close(fd);
	while (y < column)
	{
		malloc_map_two(game, map, y, fd);
		if (!map[y])
			return (ft_printf("map freed\n"),
				close(fd), free_map(map, y), NULL);
		y++;
	}
	close(fd);
	return (map);
}
