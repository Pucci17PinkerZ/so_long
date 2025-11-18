/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:36:36 by pucci             #+#    #+#             */
/*   Updated: 2025/11/18 12:53:36 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	checklength(const char *filename)	//check la longeur de la ligne comme base de referance
{
	int		i;
	int		fd;
	char	*ref_line;
	i = 0;
	fd = open(filename, O_RDONLY);
	if(!open)
		return(0);
	ref_line = get_next_line(fd);
	while(ref_line[i])
		i++;
	close(fd);
	return (i);
}

static int	checkcolumn(const char *filename)	//check le nombre de colonne(la hauteur)
{
	int		fd;
	int		count;
	char	*check;

	fd = open(filename);
	while(1)
	{
		check = get_next_line(fd);
		if(check == NULL)
			break;
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
	fd = open(filename, O_RDONLY);
	if(!open)
		return(0);
	while(ref_line != 0)
	{
		ref_line = get_next_line(fd);
		while(ref_line[i])
			i++;
		if(i != x)
			return (close(fd), free_map(), 0);
		map[y] = ft_strdup(ref_line);//check pour ce + 1 si useless ou pas
		if(!map[y])
			return (close(fd), free_map(), 0);
		y++;
	}
	close(fd);
	return (map);
}

static int	new_map(t_game *game)	//0 si error 1 si true
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	x = checklength(game->filename);
	if(!x)
		return (0);
	y = checkcolumn(game->filename);
	if(!y)
		return (0);
	game->map->map = malloc(sizeof(char *) * (y + 1));
	if(!game->map->map)//échec alloc hauteur
		return (0);
	if(malloc_map(game->filename, x, game->map->map) == 0)//échec de la largeur
		return (0);
	
}
int main (void)
{
	t_game *game;

	game->filename = "level1.ber";
	printf("%d",new_map(t_game));
}