#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_size
{
	int				width;
	int				height;
}					t_size;

typedef struct s_tab
{
	int				*tab;
	struct s_tab	*next;
}					t_tab;

# include "../../../finished/gnl/get_next_line.h"
# include "../../../finished/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

// parsing.c
size_t				count_wall(char *str);
int					parsing_handling(int fd, char *path, t_size *window_size,
						t_tab *matrice);

// utils.c
t_tab				*ft_lstlast_sl(t_tab *lst);
void				ft_lstadd_back_sl(t_tab **lst, t_tab *new);
void				free_matrice(t_tab *matrice);

// window_handling.c
// int					create_img(t_data img, int i, int	j, int color);
// void				create_map(t_data img, t_tab *matrice, t_size *window_size);

int					create_img(int color, void *mlx, void *mlx_win, int axe_x,
						int axe_y);
void				create_map(t_tab *matrice, t_size *window_size, void *mlx,
						void *mlx_win);
void				window_handling(t_size *window_size, t_tab *matrice);

#endif
