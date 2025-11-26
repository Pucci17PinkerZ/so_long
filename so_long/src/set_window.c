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

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}

int	mlx_hookloop(t_mlx *mlx)
{
	mlx_loop(mlx->mlx_ptr);
	// mlx_hook(mlx->win_ptr,/*touche pressé*/, /*0?*/,/*fonction applé*/,/*paramètre de la fonction appelé*/);
	mlx_hook(mlx->win_ptr,17,0,close_window,mlx);
	mlx_hook(mlx->win_ptr,17,0,close_window,mlx);
	return (0);
}

int mlx_windows_start(t_mlx *mlx, t_map *map, t_sprite *sprite)
{
	mlx->mlx_ptr = mlx_init();
	if(!mlx->mlx_ptr)
		return (perror("mlx_init"), 1);
	mlx->win_width = map->length * 64;
	mlx->win_height = map->column * 64;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_height, mlx->win_width, "so_long");
	if(!mlx->win_ptr)
		return (perror("mlx_new_window"), 1);
	init_sprite(mlx, sprite);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

void	init_sprite(t_mlx *mlx, t_sprite *sp)
{
	sp->img_player = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/player.xpm", &sp->img_width, &sp->img_height);
	if (!sp->img_player) {
		printf("ERREUR: impossible de charger player.xpm\n");
		exit(1);
	}
	sp->img_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/player.xpm", &sp->img_width, &sp->img_height);
	if (!sp->img_wall) {
		printf("ERREUR: impossible de charger player.xpm\n");
		exit(1);
	}
	sp->img_floor = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/player.xpm", &sp->img_width, &sp->img_height);
	if (!sp->img_floor) {
		printf("ERREUR: impossible de charger player.xpm\n");
		exit(1);
	}
		sp->img_coin = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/player.xpm", &sp->img_width, &sp->img_height);
	if (!sp->img_coin) {
		printf("ERREUR: impossible de charger player.xpm\n");
		exit(1);
	}
		sp->img_exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/player.xpm", &sp->img_width, &sp->img_height);
	if (!sp->img_exit) {
		printf("ERREUR: impossible de charger player.xpm\n");
		exit(1);
	}
	// printf("Trying to load: %s\n", "player.xpm");
	// sp->img_player = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/player.xpm",
	// 	&sp->img_width, &sp->img_height);
	// if(!sp->img_player)
	// 	return (printf("Erreur : impossible de charger player.xpm\n"), exit (1));
	// sp->img_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/wall.xpm",&sp->img_width, &sp->img_height);
	// sp->img_floor = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/floor.xpm",&sp->img_width, &sp->img_height);
	// sp->img_coin = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/coin.xpm",&sp->img_width, &sp->img_height);
	// sp->img_exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "assets/exit.xpm",&sp->img_width, &sp->img_height);
	// if (!sp->img_player || !sp->img_wall || !sp->img_floor ||!sp->img_coin || !sp->img_exit)
	// {
	// 	printf("Erreur: une texture .xpm n’a pas pu être chargée.\n");
	// 	exit(1);
	// }
}