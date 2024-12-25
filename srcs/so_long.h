#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

# include "../../gnl/get_next_line.h"
# include "../../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

size_t	count_wall(char *str);
void	window_handling(void);
void	create_wall(t_data img);

#endif
