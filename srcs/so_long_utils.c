/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:21:11 by marvin            #+#    #+#             */
/*   Updated: 2024/12/31 11:34:27 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../libft/libft.h"
#include "so_long.h"

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

t_tab	*ft_lstlast_sl(t_tab *lst)
{
	t_tab	*ptr;

	if (lst == NULL)
		return (0);
	while (lst)
	{
		ptr = lst;
		lst = lst->next;
	}
	return (ptr);
}

void	ft_lstadd_back_sl(t_tab **lst, t_tab *new)
{
	if (*lst)
		ft_lstlast_sl(*lst)->next = new;
	else
		*lst = new;
}