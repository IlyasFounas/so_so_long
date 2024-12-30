/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:51:32 by marvin            #+#    #+#             */
/*   Updated: 2024/12/30 10:55:55 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../libft/libft.h"
#include "so_long.h"

size_t	count_wall(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '1')
			j++;
		i++;
	}
	return (j);
}

int	parsing_handling(int fd, char *path, t_size *window_size)
{
	char	*line;
	int		width = 0;
	int		height = 0;
	
	line = get_next_line(fd);
	if (ft_strchr(line, '0') != NULL)
		return (free(line), 0);
	if (!line)
		return (free(path), free(line), 0);
	while (line)
	{
		width = ft_strlen(line);
		// printf("line : %s\n", line);
		free(line);
		line = get_next_line(fd);
		// if (line[0] != '1' || line[ft_strlen(line) - 3] != '1')
		// 	return (0);
		height++;
	}
	window_size->width = width;
	window_size->height = height;
	free(line);
	return (1);
}
