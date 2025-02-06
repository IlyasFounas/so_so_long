/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:43:09 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/06 12:10:27 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_the_map(char *s, int fd, int arguments)
{
	if (arguments != 2)
		return (write(2, "\n\n>> Error the program require 2 arguments <<\n\n",
				ft_strlen("\n\n>> Error the program require 2 arguments <<\n\n"
				)), 0);
	if (fd == -1)
		return (write(2, "\n\n>> Error the map doesn't exist <<\n\n",
				ft_strlen("\n\n>> Error the map doesn't exist <<\n\n")), 0);
	if (ft_strchr(s, '.') == NULL)
		return (0);
	if (ft_strncmp(ft_strchr(s, '.'), ".ber", 4) != 0 || ft_strchr(ft_strchr(s,
				'.') + 1, '.') != NULL || *(ft_strchr(s, '.') + 4) != '\0')
		return (write(2, "\n\n>> Error this map isn't a .ber extenson <<\n\n",
				ft_strlen("\n\n>> Error this map isn't a .ber extenson <<\n\n"
				)), 0);
	return (1);
}

int	main(int arv, char **arg)
{
	int		fd;
	char	*path;
	t_tab	*matrice;
	t_tab	*ptr_matrice;
	t_vars	vars;

	fd = open(arg[1], O_RDONLY);
	if (check_the_map(arg[arv - 1], fd, arv) == 0)
		return (0);
	ft_memset(&vars, 0, sizeof(t_vars));
	matrice = (t_tab *)malloc(sizeof(t_tab));
	matrice->tab = NULL;
	matrice->next = NULL;
	ptr_matrice = matrice;
	path = ft_strdup(arg[arv - 1]);
	if (!path)
		return (free(path), 0);
	if (parsing_handling(fd, path, matrice, &vars) == 0)
		exit(0);
	close(fd);
	if (is_the_map_correct(ptr_matrice, &vars) == 0 || fd == -1)
		exit(0);
	create_window(&vars);
}
