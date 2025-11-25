/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:25:50 by pucci             #+#    #+#             */
/*   Updated: 2025/11/22 20:14:03 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int main (int argc, char **argv)
{
	t_game *game;
	if(argc == 1)
	{
		printf("utilisation\n|---> ./so_long <map.ber>\n");
		return (0);
	}
	game = malloc(sizeof(t_game));
	game->filename = argv[1];
	// printf("argv[1] == %s\n", argv[1]);
	int z = new_map(game);
		printf("Return value de new_map == %d\n", z);
	int x;
	// test affichage map sur terminal
	for(int y = 0;game->map->map[y];y++)
	{
		x = 0;
		for (;game->map->map[y][x];x++)
		{
			printf("%c",game->map->map[y][x]);
		}
			// printf("%c",game->map->map[y][x + 1]);
		// printf("\n");
	}
	if(check_map(game))
	{
		printf("la map ne remplit pas les conditions :'(");
		return (0);
	}
	printf("\nla map remplit les conditions :)\n");
		
	free(game->map);
	free(game);
	
}
