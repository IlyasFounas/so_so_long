/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:43:09 by marvin            #+#    #+#             */
/*   Updated: 2025/01/08 10:16:43 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

int	main(int arv, char **arg)
{
	int		fd;
	int		res_parsing;
	char	*path;
	t_size	window_size;
	t_tab	*matrice;
	t_tab	*ptr_matrice;
	
	matrice = (t_tab *)malloc(sizeof(t_tab));
	matrice->tab = NULL;
	matrice->next = NULL;
	ptr_matrice = matrice;
	path = ft_strjoin("maps/", arg[1]);
	if (!path)
		return (free(path), 0);
	fd = open(path, O_RDONLY);
	res_parsing = parsing_handling(fd, path, &window_size, matrice);
	if (res_parsing == 0)
	{
		printf("\nla map contient une erreur ou le chemin n'est pas bon\n");
		return (0);
	}
	window_handling(&window_size, ptr_matrice);
	printf("%d", arv);
	free(path);
}
