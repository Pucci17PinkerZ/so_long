/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:25:50 by pucci             #+#    #+#             */
/*   Updated: 2025/11/26 18:45:21 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


int main (int argc, char **argv)
{
	t_game	game;
	if(argc == 1)
	{
		printf("utilisation\n|----> ./so_long <map.ber>\n");
		return (0);
	}
	init_game(&game);
	// ft_memset(&game, 0, sizeof(t_game));
	// ft_memset(&game.mlx, 0, sizeof(t_mlx));
	// ft_memset(&game.map, 0, sizeof(t_map));
	// ft_memset(&game.sprite, 0, sizeof(t_sprite));

	game.sprite.img_height = 64;
	game.sprite.img_width = 64;
	game.filename = argv[1];
	// printf("argv[1] == %s\n", argv[1]);
	int z = new_map(&game);
		printf("Return value de new_map == %d\n", z);

	if(check_map(&game))
	{
		printf("la map ne remplit pas les conditions :'(");
		return (0);
	}
	printf("\nla map remplit les conditions :)\n");
		
	mlx_windows_start(&game);
	
}
