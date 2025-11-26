/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:25:50 by pucci             #+#    #+#             */
/*   Updated: 2025/11/26 18:18:29 by pucci            ###   ########.fr       */
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
	// set_game(game,argv[1]);
	game = malloc(sizeof(t_game));
	game->sprite = malloc(sizeof(t_sprite));
	game->mlx = malloc(sizeof(t_mlx));
	game->map = malloc(sizeof(t_map));
	game->sprite->img_height = 128;
	game->sprite->img_width = 128;
	game->filename = argv[1];
	// printf("argv[1] == %s\n", argv[1]);
	int z = new_map(game);
		printf("Return value de new_map == %d\n", z);

	if(check_map(game))
	{
		printf("la map ne remplit pas les conditions :'(");
		return (0);
	}
	printf("\nla map remplit les conditions :)\n");
		
	mlx_windows_start(game->mlx, game->map, game->sprite);

	free(game->map);
	free(game);
}
