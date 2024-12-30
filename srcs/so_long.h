#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_size
{
	int		width;
	int		height;
}			t_size;

# include "../../gnl/get_next_line.h"
# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

size_t		count_wall(char *str);
void		window_handling(t_size *window_size);
int			parsing_handling(int fd, char *path, t_size *window_size);
int			create_wall(t_data img, int i);
int			create_floor(t_data img, int i);

#endif
