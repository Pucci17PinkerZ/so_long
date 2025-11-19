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
} t_map;


typedef struct s_game
{
	const char *filename;
	t_map *map;
} t_game ;


int *read_map(const char *filename, t_game *game);

//pour new_map
static int	new_map(t_game *game);
static char	**malloc_map(const char *filename, int x, char **map);
static int	check_column(const char *filename);
static int	check_length(const char *filename);

//pour les leaks
void	free_map(char **map, int y);

#endif