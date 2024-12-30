/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:43:09 by marvin            #+#    #+#             */
/*   Updated: 2024/12/30 10:45:26 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

int	main(int arv, char **arg)
{
	int		fd;
	int		res_parsing;
	char	*path;
	t_size	window_size;

	path = ft_strjoin("maps/", arg[1]);
	if (!path)
		return (free(path), 0);
	fd = open(path, O_RDONLY);
	res_parsing = parsing_handling(fd, path, &window_size);
	
	//gere les messages d'erreurs
	if (res_parsing == 0)
	{
		printf("\nla map contient une erreur ou le chemin n'est pas bon\n");
		return (0);
	}
	printf("res_parsing = %d\n", res_parsing);
	window_handling(&window_size);
	printf("%d", arv);
	free(path);
}
