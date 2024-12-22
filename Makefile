# NAME    = so_long
# SRC     = srcs/main.c \
#           ../gnl/get_next_line.c \
#           ../gnl/get_next_line_utils.c
# OBJ_DIR = objs
# OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
# CFLAGS  = -Wall -Wextra -Werror
# CC      = cc

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# $(OBJ_DIR)/%.o: srcs/%.c
# 	mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR)/%.o: ../gnl/%.c
# 	mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -rf $(OBJ_DIR)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# run: $(NAME)
# 	$(CC) $(CFLAGS) $(SRC) -o a.out
# 	./a.out

# all: $(NAME)

# .PHONY: all clean fclean re run

NAME    = so_long
SRC     = srcs/main.c \
          ../gnl/get_next_line.c \
          ../gnl/get_next_line_utils.c
OBJ_DIR = objs
OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
CFLAGS  = -Wall -Wextra -Werror -Imlx-linux -I/usr/include
CC      = cc

# Dépendances MiniLibX
MLX_DIR = minilibx-linux
MLX_LIBS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ../gnl/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

all: $(NAME)

.PHONY: all clean fclean re run

