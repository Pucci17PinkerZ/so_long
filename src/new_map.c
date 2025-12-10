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

int	check_length(const char *filename)
{
	int		i;
	int		fd;
	char	*ref_line;
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return(-1);
	ref_line = get_next_line(fd);
	if (ref_line == NULL)
		return (-1);
	while (ref_line[i] != '\n')
		i++;
	close(fd);
	return (free(ref_line), i);
}

int	check_column(const char *filename)
{
	int		fd;
	int		count;
	char	*check;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		check = get_next_line(fd);
		if (check == NULL)
			break;
		if (check[0] == '\n') 
			return (free(check),-1);
		count++;
		free(check);
	}
	close(fd);
	return (count);
}

char	**malloc_map(const char *filename, int x, int column, char **map)
{
	int i;
	int y;
	int fd;
	char *ref_line;

	i = 0;
	y = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1 || !map)
		return (NULL);

	while(y < column)
	{
		ref_line = get_next_line(fd);
		if (column - 1 == y && ref_line[x] == '\n')
			return (NULL);
		if (ref_line == NULL)
			break ;
		i = 0;
		while (ref_line[i] != '\n' && ref_line[i] != '\0')
			i++;
		if (i != x)
			return (close(fd), free_map(map , y), NULL);

		map[y] = ft_substr(ref_line, 0, x + 1);
		free(ref_line);
		if (!map[y])
			return (close(fd), free_map(map, y), NULL);
		y++;
	}
	close(fd);
	return (map);
}

int	new_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	x = check_length(game->filename);
	if (x == -1)
		return (-1);
	y = check_column(game->filename);
	if (y == -1)
		return (-1);
	game->map.column = y;
	game->map.length = x;
	game->map.map = malloc(sizeof(char *) * (y + 1));
	if (!game->map.map)
		return (-1);
	if (malloc_map(game->filename, x, y, game->map.map) == NULL)
		return (-1);
	return (0);
}
