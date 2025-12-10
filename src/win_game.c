#include "so_long.h"

void	all_coin_collected(t_game * game)
{
	if(game->map.coins_count == game->map.coins_found)
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr,game->mlx.win_ptr, game->sprite.img_exit, game->hidden_door_x * 128, game->hidden_door_y * 128);
	}
	if(game->map.coins_count == game->map.coins_found 
		&& game->hidden_door_y == game->player_y 
		&&game->hidden_door_x == game->player_x)
	{
		printf("you won!\n");
		close_window(game);
		exit (0);
	}
}