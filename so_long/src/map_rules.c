/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:42:07 by nfiora-d          #+#    #+#             */
/*   Updated: 2025/11/18 10:36:20 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int scan_item(char c)
{
	if(c == '')
}

int	scan_map(char c, int x,int y, t_game *game)
{
	if(y == 0 || y == game->map->column)
	{
		if(c != '1')
		return (-1);
	}
	else if(x == 0 || x == game->map->length)
	{
		if(c != '1')
			return (-1);
	}
	else
	{
		
	}
		scan_item();
}

int check_map(t_game *game)//check des chars c'est plus esazzy
{
	int y;


	y = 0;
	while(game->map->map[y])
	{
		while(game->map->map[y][x])
		{
			// if(game->map->map[0][x] != '1' 
			// 	|| game->map->map[game->map->column][x] != '1')
			if(scan_map())
				return (-1);
			x++;
		}
		// if(game->map->map[y][0] != 1 
		// 	|| game->map->map[y][game->map->length] != 1)
		// 	return (-1);
		y++;
	}
	return (1);
}

int check_map(t_game *game) // fonction principale qui rassemble tout les checks
{
	
	if(check_walls(game) == -1)//on check si les murs sont good
		return (-1);// on free?

}


int check_line(char *line, int countline, int column, int length)	//fait les check suivants : les murs, la taille X * Y, les collectibles
{
	if(countline == 1 || countline == column) //check top et down
	{
		while(*line)
		{
			if(*line != 1)
				return (1);
			line++;
		}
	}
	else //check le mid
	{
		while(*line)
		{
			if(*line != 1 || *line != 'E' || *line != 'C' || *line != 'P')
				return (1);
			line++;
		}
		i != length 
			return (1);
	}
	return (0);
}



int main (void)
{
	char tab[] = "level1";
	printf("%d",checklength(tab));
}
//Purpose: Reads the map file and populates the game’s map array.
//Implementation Tips:
//Check that each line is the same length.
//Count the number of player starts (P), exits (E), and collectibles (C).
//Ensure the map is surrounded by walls (1).