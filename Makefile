NAME    = so_long
SRC     = srcs/create_window.c \
          srcs/event_deplacements.c \
          srcs/find_t_axes.c \
          srcs/ft_flood_fill.c \
		  srcs/main.c \
          srcs/manage_errors.c \
          srcs/map_parsing.c \
          ft_printf/ft_printf.c \
          ft_printf/ft_printf_utils.c \
          gnl/get_next_line.c \
          gnl/get_next_line_utils.c
OBJ_DIR = objs
OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
CFLAGS = -Wall -Wextra -Werror -g3 -Imlx-linux -I/usr/include -I libft -I ft_printf -I gnl -I includes -I minilibx-linux
CC      = cc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIBS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLX_LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c gnl/get_next_line.h 
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: gnl/%.c gnl/get_next_line.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ft_printf/%.c ft_printf/ft_printf.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

run: $(NAME)
	./$(NAME) maps/map2.ber

all: $(NAME)

.PHONY: all clean fclean re run