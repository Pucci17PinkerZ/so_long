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

    //    void *
    //    mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

    //    int
    //    mlx_clear_window ( void *mlx_ptr, void *win_ptr );

    //    int
    //    mlx_destroy_window ( void *mlx_ptr, void *win_ptr );


# include "so_long.h"

/*

*/

int mlx_windows_start(void)
{
	void *mlx_ptr;
	void *win_ptr;//identifiant de la fentre

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 64, 64, "so_long");
	(void)win_ptr;
	mlx_loop(mlx_ptr);//mlx loop gère les évenemnt
	return (0);
}


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
		
	mlx_windows_start();

	free(game->map);
	free(game);
	
}
