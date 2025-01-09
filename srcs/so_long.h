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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*hero;
	int	**matrice_of_m;
	int	width;
	int	height;
}				t_vars;

typedef struct	s_axes {
	int	axe_x;
	int	axe_y;
	int	yes_or_no;
}				t_axes;

// # include "../../gnl/get_next_line.h"
// # include "../../libft/libft.h"
# include "../../../finished/gnl/get_next_line.h"
# include "../../../finished/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// utils.c
t_tab	*ft_lstlast_sl(t_tab *lst);
void	ft_lstadd_back_sl(t_tab **lst, t_tab *new);
void	free_matrice(t_tab *matrice);

// event_utils.c
int finished_or_not(t_vars *vars);
void	allow_to_exit(t_vars *vars, char *path);
void	finish_the_game(t_vars *vars);

// event_handling.c
t_axes	*find_t_axes(t_vars *vars, char *path);

// event_managing.c
int	manage_event(int keycode, t_vars *vars);

// window_handling.c
void	window_handling(t_size *window_size, t_tab *matrice);

// find_errors_in_map
// >>>>>>>TODO<<<<<<<

// parsing.c
int	parsing_handling(int fd, char *path, t_size *window_size, t_tab *matrice);

#endif
