void set_game(t_game *game, char *filename)
{
	game = malloc(sizeof(t_game));
	game->filename = filename;
	game->map = malloc(sizeof(t_map));
	game->map->length = 0;
	game->map->column = 0;
}