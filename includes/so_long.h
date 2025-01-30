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

# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>

// main.c
int finished_or_not(t_vars *vars);
void	allow_to_exit(t_vars *vars, char *path);
void	finish_the_game(t_vars *vars, int deplacement_count, t_axes *hero_axes);

// find_good_path
int	ft_flood_fill(t_vars *vars);

// find_t_axes.c
t_axes	*find_t_axes(t_vars *vars, char *path);
int	create_object(t_vars *vars, char *path, int axe_x, int axe_y);

// manage_events.c
int	manage_events(int keycode, t_vars *vars);

// window_handling.c
void	create_window(t_vars *vars);

// manage_errors.c
int	is_the_map_correct(t_tab *ptr_matrice, t_vars *vars);

// map_parsing.c
void	free_matrice(t_tab *matrice);
int	parsing_handling(int fd, char *path, t_tab *matrice, t_vars *vars);

#endif
