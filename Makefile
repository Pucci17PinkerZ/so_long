CC = cc
NAME = so_long
DIRGNL = gnl
DIRSRC = src
DIRLIBFT = libft
DIRMLX = mlx
DIRPRINTF = ft_printf
LIBFT_LIB = $(DIRLIBFT)/libft.a
MLX_LIB = $(DIRMLX)/libmlx.a
PRINTF_LIB = $(DIRPRINTF)/libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I/usr/include -I$(DIRMLX) -I$(DIRLIBFT) -I$(DIRPRINTF) -I$(DIRSRC) -I$(DIRGNL)
LDFLAGS = -L$(DIRMLX) -lmlx -lXext -lX11
RM = rm -rf

SRC = $(DIRSRC)/so_long.c \
	$(DIRSRC)/new_map.c\
	$(DIRSRC)/new_map_two.c\
	$(DIRSRC)/player_move.c\
	$(DIRSRC)/map_rules.c\
	$(DIRSRC)/free_them.c\
	$(DIRSRC)/floodfill.c\
	$(DIRSRC)/set_window.c\
	$(DIRSRC)/win_game.c\
	$(DIRSRC)/set_game.c\
	$(DIRGNL)/get_next_line.c \
	$(DIRGNL)/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(LIBFT_LIB) $(PRINTF_LIB) $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(DIRMLX)

$(PRINTF_LIB):
	@make -C $(DIRPRINTF)

$(LIBFT_LIB):
	@make -C $(DIRLIBFT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(LDFLAGS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	@make clean -C $(DIRLIBFT)
	@make clean -C $(DIRPRINTF)
	@make clean -C $(DIRMLX)

fclean: clean
	$(RM) $(NAME)
	$(RM) libft.a
	@make fclean -C $(DIRLIBFT)
	@make fclean -C $(DIRPRINTF)

re: fclean all

.PHONY: all clean fclean re