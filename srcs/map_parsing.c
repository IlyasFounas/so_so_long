/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:51:32 by marvin            #+#    #+#             */
/*   Updated: 2025/01/10 11:38:43 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "../../libft/libft.h"
#include "../../../finished/libft/libft.h"
#include "../includes/so_long.h"


void	free_matrice(t_tab *matrice)
{
	t_tab	*tmp;

	while (matrice)
	{
		tmp = matrice->next;
		if (matrice->tab)
			free(matrice->tab);
		free(matrice);
		matrice = tmp;
	}
}

static t_tab *ft_lstlast_sl(t_tab *lst)
{
    t_tab *ptr;

    if (!lst)
        return (NULL);
    while (lst)
    {
        ptr = lst;
        lst = lst->next;
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
	int i = 0;
	t_tab *new_matrice;
	
	new_matrice = (t_tab *)malloc(sizeof(t_tab));
	if (!new_matrice)
		return (free(line), NULL);
	new_matrice->tab = malloc(ft_strlen(line) * sizeof(int));
	if (!new_matrice->tab)
		return (free(line), NULL);
	while (line[i] && line[i] != '\n')
	{
		if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A'
				&& line[i] <= 'Z') || (line[i] >= '0' && line[i] <= '9'))
			new_matrice->tab[i] = line[i] - 48;
		i++;
	}
	return (new_matrice);
}

int	parsing_handling(int fd, char *path, t_size *window_size, t_tab *matrice)
{
	char	*line;
	t_tab	*new_matrice;

	line = get_next_line(fd);
	if (!line)
		return (free(path), free(line), 0);
	while (line)
	{
		window_size->width = ft_strlen(line);
		new_matrice = fill_the_matrice(line);
		if (!new_matrice)
			return (0);
		free(line);
		line = get_next_line(fd);
		if (new_matrice != NULL)
			ft_lstadd_back_sl(&matrice, new_matrice);
		window_size->height++;
	}
	free(line);
	return (1);
}
