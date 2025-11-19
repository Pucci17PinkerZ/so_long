/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:36:36 by pucci             #+#    #+#             */
/*   Updated: 2025/11/18 18:55:17 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_length(const char *filename)	//check la longeur de la ligne comme base de referance
{
	int		i;
	int		fd;
	char	*ref_line;
	i = 0;
	fd = open(filename, O_RDONLY);
	if(fd == -1)
		return(-1);
	ref_line = get_next_line(fd);
	if(ref_line == NULL)
		return (-1);
	while(ref_line[i])
		i++;
	close(fd);
	return (free(ref_line), i);
}

static int	check_column(const char *filename)	//check le nombre de colonne(la hauteur)
{
	int		fd;
	int		count;
	char	*check;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while(1)
	{
		check = get_next_line(fd);
		if(check == NULL)
			break ;
		free(check);
		count++;
	}
	close(fd);
	return (count);
}


static char	**malloc_map(const char *filename, int x, char **map)	//check la longeur de la ligne comme base de referance
{
	int i;
	int y;
	int fd;
	char *ref_line;

	i = 0;
	y = 0;
	fd = open(filename, O_RDONLY);
	if(fd == -1 || !map)
		return (NULL);
	while(y < x)
	{
		ref_line = get_next_line(fd);//est ce que je devrai mettre un check si je check plus haud dans
		if(ref_line == NULL)
			break ;
		i = 0;
		while(ref_line[i])
			i++;
		if(i != x)
			return (close(fd), free_map(map , y), NULL);
		map[y] = ft_strdup(ref_line);//check pour ce + 1 si useless ou pas
		free(ref_line);
		if(!map[y])
			return (close(fd), free_map(map, y), NULL);
		y++;
	}
	close(fd);
	return (map);
}

int set_coords()

static int	new_map(t_game *game)	//-1 si error 1 si true
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	x = check_length(game->filename);
	if(x == -1)
		return (-1);
	y = check_column(game->filename);
	if(y == -1)
		return (-1);
	game->map = malloc(sizeof(t_map));
	if(!game->map)
		return (-1);
	game->map->map = malloc(sizeof(char *) * (y + 1));
	if(!game->map->map)//échec alloc hauteur
		return (free(game->map), -1);
	if(malloc_map(game->filename, x, game->map->map) == NULL)//échec de la largeur
		return (free(game->map), -1);
	return (1);
}

int main (void)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	game->filename = "level1.ber";
	printf("%d",new_map(game));
	printf("%c",game->map->map[1][1]);
	free(game);
}