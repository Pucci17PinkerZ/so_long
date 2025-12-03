CC = gcc
NAME = so_long.a
DIRGNL = gnl
DIRSRC = src
DIRLIBFT = libft
LIBFT_LIB = $(DIRLIBFT)/libft.a
DIRMLX = mlx
MLX_LIB = $(DIRMLX)/libmlx.a
DIRPRINTF = ft_printf
PRINTF_LIB = $(DIRPRINTF)/libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g

SRC = $(DIRSRC)/so_long.c \
	$(DIRSRC)/new_map.c\
	$(DIRSRC)/map_rules.c\
	$(DIRSRC)/free_them.c\
	$(DIRSRC)/floodfill.c\
	$(DIRSRC)/set_window.c\
	$(DIRSRC)/set_game.c\
	$(DIRGNL)/get_next_line.c \
	$(DIRGNL)/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)
LDFLAGS = -L$(DIRMLX) -lmlx -lXext -lX11
RM = rm -rf


NB := $(words $(SRC))
BARLEN = 30

%.o: %.c
	@$(eval CNT := $(shell ls $(DIRSRC)/*.o $(DIRGNL)/*.o $(DIRLIBFT)/*.o $(DIRPRINTF)/*.o 2>/dev/null | wc -l))
	@$(eval PROG := $(shell echo $$(($(CNT) * 100 / $(NB))) ))
	@$(eval FILLED := $(shell echo $$(($(PROG) * $(BARLEN) / 100)) ))
	@$(eval EMPTY := $(shell echo $$(($(BARLEN) - $(FILLED))) ))
	@$(CC) $(CFLAGS) -c $< -o $@

	@$(CC) $(CFLAGS) -c $< -o $@

# --------------------------------------------------------

all: $(LIBFT_LIB) $(PRINTF_LIB) $(MLX_LIB) $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(DIRMLX) --no-print-directory > /dev/null

$(PRINTF_LIB):
	$(MAKE) -C $(DIRPRINTF)

$(LIBFT_LIB):
	$(MAKE) -C $(DIRLIBFT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(LDFLAGS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(DIRMLX) clean --no-print-directory > /dev/null
	$(MAKE) -C $(DIRPRINTF) clean --no-print-directory > /dev/null
	$(MAKE) -C $(DIRLIBFT) clean --no-print-directory > /dev/null

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIRMLX) clean --no-print-directory > /dev/null
	$(MAKE) -C $(DIRPRINTF) clean --no-print-directory > /dev/null
	$(MAKE) -C $(DIRLIBFT) clean --no-print-directory > /dev/null

re: fclean all

.PHONY: all clean fclean re