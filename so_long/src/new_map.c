/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:36:36 by pucci             #+#    #+#             */
/*   Updated: 2025/11/22 20:46:21 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_length(const char *filename)	//check la longeur de la ligne comme base de referance
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
	while(ref_line[i] != '\n')
		i++;
	// printf("\naprès le comptage x vaut == %d en longeur de tableau\n", i);
	close(fd);
	return (free(ref_line), i - 1);
}

int	check_column(const char *filename)	//check le nombre de colonne(la hauteur)
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
	// printf("\nle nombre de colonne est de 5 le programme encompte == %d en valeur de tableau\n", count);
	return (count - 1);
}

char	**malloc_map(const char *filename, int x, int column, char **map)	//check la longeur de la ligne comme base de referance
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
			printf("column == %d\n",column);
	while(y <= column)
	{
		printf("y == %d\n",y);
		ref_line = get_next_line(fd);
		if(ref_line == NULL)
			break ;
		if (ref_line[0] == '\n')
		{
			printf("\nje passe par ref_line[0] == '\n'\n");
			free(ref_line);
			break;
		}
		i = 0;
		if(y == column)
		{
			while(i < column)
						i++;
			printf("\ni == %d\n x == %d\n",i,x);
			if(i != x)
				return (close(fd), free_map(map , y), NULL);
		}
		else
		{
			while(ref_line[i] != '\n')
				i++;
			if((i - 1) != x)
				return (close(fd), free_map(map , y), NULL);
		}
		map[y] = ft_substr(ref_line, 0, x + 1);
		free(ref_line);
		if(!map[y])
			return (close(fd), free_map(map, y), NULL);
		y++;
	}
	close(fd);
	return (map);
}

int	new_map(t_game *game)	//-1 si error 1 si true
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
	game->map = malloc(sizeof(t_map));//t_map alloué
	if(!game->map)
		return (-1);
	game->map->column = y;
	game->map->length = x;
	// printf("en theorie x vaut 4 ---> le programme la compte comme %d\n", x);
	printf("\nen theorie y vaut 5 et devrai valoir 4 ---> le programme la compte comme %d\n\n", y);
	game->map->map = malloc(sizeof(char *) * (y + 1));
	// printf("on malloc la dimention y avec %d + 1", y);
	if(!game->map->map)//échec alloc hauteur
		return (free(game->map), -1);
	if(malloc_map(game->filename, x, y, game->map->map) == NULL)//
		return (free(game->map), -1);
	return (0);
}
