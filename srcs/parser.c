/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:51:32 by marvin            #+#    #+#             */
/*   Updated: 2025/01/05 11:48:41 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "../../libft/libft.h"
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

//TODO : Function that verif the map : int verif_map();

int	parsing_handling(int fd, char *path, t_size *window_size, t_tab *matrice)
{
	char	*line;
	int		width;
	int		height;
	int		i;
	t_tab *new_matrice;

	width = 0;
	height = 0;
	i = 0;
	line = get_next_line(fd);
	if (ft_strchr(line, '0') != NULL)
		return (free(line), 0);
	if (!line)
		return (free(path), free(line), 0);
	while (line)
	{
		width = ft_strlen(line);
		new_matrice = (t_tab *)malloc(sizeof(t_tab));
		if (!new_matrice)
			return (free(line), 0);
		new_matrice->tab = malloc(ft_strlen(line) * sizeof(int));
		if (!new_matrice->tab)
			return (free(line), 0);
		while (line[i] && line[i] != '\n')
		{
			if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A'
					&& line[i] <= 'Z') || (line[i] >= '0' && line[i] <= '9'))
				new_matrice->tab[i] = line[i] - 48;
			i++;
		}
		i = 0;
		free(line);
		line = get_next_line(fd);
		
		ft_lstadd_back_sl(&matrice, new_matrice);
		height++;
	}
	window_size->width = width;
	window_size->height = height;
	free(line);
	return (1);
}
