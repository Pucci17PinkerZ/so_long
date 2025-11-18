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

int checkcolumn(const char *filename);
int check_line(char *line, int countline, int column, int length);
int checklength(const char *filename);

int	read_map(const char *filename, t_game *game) // file dans struct
{
	int fd;
	int countline;
	int column;//hauteur
	int length;//longeur
	char *line;

	column = checkcolumn(filename);
	length = checklength(filename);
	countline = 0;
	fd = open(filename);	//check aussi si le fichier à bien été ouvert?

	while (1)//boucle infine
	{
		line = get_next_line(fd);
		if (line == NULL)
		countline++;
		if(check_line(line, countline, column, length) == 1)//comment gerer la sortie d'erreur? faire en sorte de voir ce qu'il check
			break ;
	}
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

int checklength(const char *filename)	//check la longeur de la ligne comme base de referance
{
	int i;
	int fd;
	char *ref_line;

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