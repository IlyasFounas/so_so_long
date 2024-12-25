/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:43:09 by marvin            #+#    #+#             */
/*   Updated: 2024/12/25 21:58:12 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

int	main(int arv, char **arg)
{
	int		fd;
	char	*line;
	char	*path;

	path = ft_strjoin("maps/", arg[1]);
	if (!path)
		return (free(path), 0);
	printf("%d", arv);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (free(path),free(line),0);
	while (line)
	{
		printf("line : %s", line);
		printf("nb of wall : %zu\n", count_wall(line));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	window_handling();
	free(path);
}
