/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:51:32 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/06 12:18:06 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_tab	*ft_lstlast_sl(t_tab *lst)
{
	t_tab	*ptr;

	if (!lst)
		return (NULL);
	while (lst)
	{
		ptr = lst;
		lst = lst->next;
		if (!lst)
			return (ptr);
	}
	return (ptr);
}

static void	ft_lstadd_back_sl(t_tab **lst, t_tab *new)
{
	if (*lst)
		ft_lstlast_sl(*lst)->next = new;
	else
		*lst = new;
}

static t_tab	*fill_the_matrice(char *line)
{
	int		i;
	t_tab	*new_matrice;

	i = 0;
	new_matrice = (t_tab *)malloc(sizeof(t_tab));
	if (!new_matrice)
		return (free(line), NULL);
	new_matrice->tab = malloc(ft_strlen(line) * sizeof(int));
	new_matrice->next = NULL;
	if (!new_matrice->tab)
		return (free(line), NULL);
	while (line[i] && line[i] != '\n')
	{
		if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A'
				&& line[i] <= 'Z') || (line[i] >= '0' && line[i] <= '9'))
			new_matrice->tab[i] = line[i] - 48;
		else
			return (free(new_matrice->tab), free(new_matrice), NULL);
		i++;
	}
	return (new_matrice);
}

int	fill_the_big_matrice(t_vars *vars, int verif_rectangle, t_tab *matrice,
		char *line)
{
	t_tab	*new_matrice;

	if (verif_rectangle == 0)
	{
		if (line[(int)ft_strlen(line) - 1] == '\n')
			verif_rectangle = (int)ft_strlen(line) - 1;
		else
			verif_rectangle = (int)ft_strlen(line);
	}
	if (line[(int)ft_strlen(line) - 1] == '\n')
		vars->width = (int)ft_strlen(line) - 1;
	else
		vars->width = (int)ft_strlen(line);
	if (line[vars->width - 1] != '\n')
		if (verif_rectangle != vars->width)
			return (0);
	new_matrice = fill_the_matrice(line);
	if (!new_matrice)
		return (0);
	if (new_matrice != NULL)
		ft_lstadd_back_sl(&matrice, new_matrice);
	return (1);
}

int	parsing_handling(int fd, char *path, t_tab *matrice, t_vars *vars)
{
	char	*line;
	int		verif_rectangle;

	verif_rectangle = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 1) != 0)
		{
			if (fill_the_big_matrice(vars, verif_rectangle, matrice, line) == 0)
				return (free(line), free(path), free_matrice(matrice), 0);
			vars->height++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (vars->height < 1)
		return (manage_error_map_parsing(line, path, matrice));
	free(line);
	free(path);
	return (1);
}
