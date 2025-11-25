#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
// # include "../mlx/mlx.h"
// # include "../printf/ft_printf.h"


typedef struct s_map
{
	char **map;
	int length;
	int column;
	int coins_count;
	int player_count;
	int exit_count;
} t_map;

typedef struct s_game
{
	const char *filename;
	t_map *map;
} t_game ;


int *read_map(const char *filename, t_game *game);

//pour new_map
int	new_map(t_game *game);
char	**malloc_map(const char *filename, int x, int column, char **map);
int	check_column(const char *filename);
int	check_length(const char *filename);

//pour les check de map
int	scan_item(char c, t_game *game);
int	scan_map(char c, int x,int y, t_game *game);
int count_item(t_game *game);
int	check_map(t_game *game);
int	floodfill(t_game *game, int y, int x);

//pour les leaks
void	free_map(char **map, int y);

#endif