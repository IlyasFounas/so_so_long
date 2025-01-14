/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_good_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:15:23 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/14 18:52:57 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

int	**verif_vertic(t_vars *vars)
{
	int	**tab;
	int	x2;
	int	y2;

	x2 = -1;
	y2 = -1;
	tab = malloc((vars->height + 1) * sizeof(int *));
	if (!tab)
		return (NULL);
	while (++y2 < vars->height)
	{
		tab[y2] = malloc((vars->width) * sizeof(int));
		if (!tab[y2])
			return (NULL);
		while (++x2 < vars->width)
			tab[y2][x2] = vars->matrice_of_m[y2 + 1][x2];
		x2 = -1;
	}
	return (tab);
}

int	**pathing_matrice(int **tab, int y, int x, int h, int w)
{
	int xx;

	xx = x;
	while (y <= h)
	{
		while (x < w && tab[y][x] != 1)
		{
			printf("%d\n", tab[y][x]);
			tab[y][x] = 'X';
			x++;
		}
		x = xx;
	}
	return (tab);
}

int	is_the_path_valid_or_not(t_vars *vars)
{
	int	y;
	int	x;
	int	**tab;

	y = -1;
	x = -1;
	tab = verif_vertic(vars);	
	while (++y < vars->height)
	{
		while (++x < vars->width)
		{
			ft_printf("%d ", tab[y][x]);
		}
		ft_printf("\n");
		x = -1;
	}
	// int	breaks;
	// breaks = 0;
	// while (++y <= vars->height)
	// {
	// 	while (++x < vars->width)
	// 	{
	// 		if (vars->matrice_of_m[y][x] == 'P')
	// 		{
	// 			tab = pathing_matrice(tab, y, x, vars->height, vars->width);
	// 			breaks = 1;
	// 			break ;
	// 		}
	// 	}
	// 	if (breaks == 1)
	// 		break;
	// 	x = -1;
	// }
	// y = -1;
	// x = -1;

	return (1);
}
