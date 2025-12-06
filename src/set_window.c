/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci <pucci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:57:15 by pucci             #+#    #+#             */
/*   Updated: 2025/11/26 18:50:07 by pucci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
/*  ========================FONCTION QUI AGISSEMNT DANS LA LOOP======================*/
int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	return (0);
}

void	move_
/* ===================================================================== */
int	mlx_hookloop(t_game *game)
{
	// mlx_hook(mlx.win_ptr,/*touche pressé*/, /*0?*/,/*fonction applé*/,/*paramètre de la fonction appelé*/);
	mlx_hook(game->mlx.win_ptr, 17, 0, close_window, game);
	// mlx_hook(game->mlx.win_ptr,17,0,close_window,game->mlx);
	mlx_loop(game->mlx.mlx_ptr);
	return (0);
}

int	load_sprite(t_game *game)
{
	game->sprite.img_player = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "assets/player1.xpm", &game->sprite.img_width, &game->sprite.img_height);
	if (!game->sprite.img_player) 
		return (printf("ERREUR: impossible de charger player.xpm\n"), 1);
	game->sprite.img_wall = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "assets/wall1.xpm", &game->sprite.img_width , &game->sprite.img_height);
	if (!game->sprite.img_wall) 
		return (printf("ERREUR: impossible de charger wall.xpm\n"), 1);
	game->sprite.img_floor = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "assets/floor1.xpm", &game->sprite.img_width, &game->sprite.img_height);
	if (!game->sprite.img_floor) 
		return (printf("ERREUR: impossible de charger floor.xpm\n"), 1);
	game->sprite.img_coin = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "assets/coin1.xpm", &game->sprite.img_width, &game->sprite.img_height);
	if (!game->sprite.img_coin) 
		return (printf("ERREUR: impossible de charger coin.xpm\n"), 1);
	game->sprite.img_exit = mlx_xpm_file_to_image(game->mlx.mlx_ptr, "assets/exit1.xpm", &game->sprite.img_width, &game->sprite.img_height);
	if (!game->sprite.img_exit) 
		return (printf("ERREUR: impossible de charger exit.xpm\n"), 1);
	return (0);
}

int	put_img(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < game->map.column)
	{
		x = 0;
		while(x < game->map.length)
		{
			printf("\nx == %d\ny == %d\n la vale à game->map->map[%d][%d] est de '%c'\n", x, y, y, x, game->map.map[y][x]);
			sprite_to_put(game, x, y);
			x++;
		}
		y++;
	}
	
	return (0);
}
int sprite_to_put(t_game *game, int x , int y)
{
	if(game->map.map[y][x] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->sprite.img_floor, x * 128, y * 128);
		printf("\nfloor à été utilisé\n");
	}

	if(game->map.map[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->sprite.img_wall, x * 128, y * 128);
		printf("\nwall à été utilisé\n");
	}

	if(game->map.map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->sprite.img_player, x * 128, y * 128);
		printf("\nplayer à été utilisé\n");
	}

	if(game->map.map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->sprite.img_exit, x * 128, y * 128);
		printf("\nexit à été utilisé\n");
	}

	if(game->map.map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->sprite.img_coin, x * 128, y * 128);
		printf("\ncoin à été utilisé\n");
	}
	return (0);
}

int mlx_windows_start(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if(!game->mlx.mlx_ptr)
		return (perror("mlx_init"), 1);
	game->mlx.win_width = game->map.length * 128;
	game->mlx.win_height = game->map.column * 128;
	printf("DEBUG: Création fenêtre %dx%d\n", game->mlx.win_width, game->mlx.win_height);
	printf("comlumn == %d\n length == %d\n",game->map.column, game->map.length);


	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,game->mlx.win_width , game->mlx.win_height, "so_long");
	if(!game->mlx.win_ptr)
		return (perror("mlx_new_window"), 1);
	load_sprite(game);
	put_img(game);
	mlx_hookloop(game);
	return (0);
}