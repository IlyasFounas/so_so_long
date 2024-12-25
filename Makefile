# NAME    = so_long
# SRC     = srcs/main.c \
# 		  srcs/parser.c \
# 		  srcs/window_handling.c \
#           ../gnl/get_next_line_utils.c \
#           ../gnl/get_next_line.c 
# OBJ_DIR = objs
# OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
# CFLAGS  = -Wall -Wextra -Werror -Imlx-linux -I/usr/include
# CC      = cc

# # Dépendances MiniLibX
# MLX_DIR = minilibx-linux
# MLX_LIBS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) $(MLX_LIBS) -o $(NAME)

# $(OBJ_DIR)/%.o: srcs/%.c ../gnl/get_next_line.h
# 	mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR)/%.o: ../gnl/%.c ../gnl/get_next_line.h
# 	mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@


# clean:
# 	rm -rf $(OBJ_DIR)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# run: $(NAME)
# 	./$(NAME) map1.ber

# all: $(NAME)

# .PHONY: all clean fclean re run


NAME    = so_long
SRC     = srcs/main.c \
          srcs/parser.c \
          srcs/window_handling.c \
          ../gnl/get_next_line.c \
          ../gnl/get_next_line_utils.c
OBJ_DIR = objs
OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
CFLAGS  = -Wall -Wextra -Werror -Imlx-linux -I/usr/include -I../libft/includes
CC      = cc

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIBS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLX_LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c ../gnl/get_next_line.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ../gnl/%.c ../gnl/get_next_line.h
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
	./$(NAME) map1.ber

all: $(NAME)

.PHONY: all clean fclean re run
