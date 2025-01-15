/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_good_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:15:23 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/15 18:04:21 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

int	**matrice_cpy_for_path(t_vars *vars)
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

void	fill_the_path2(int **tab, int y, int x, int w, int h)
{
	if (tab[y][x] != 1)
	{
		tab[y][x] = 'X';
		if (tab[y - 1][x] != 1)
			fill_the_path2(tab, y - 1, x, w, h);
		if (tab[y][x + 1] != 1)
			fill_the_path2(tab, y, x + 1, w, h);
	}
	else
		return ;
}


void	fill_the_path(int **tab, int y, int x, int w, int h)
{
	if (tab[y][x] != 1)
	{
		tab[y][x] = 'X';
		if (tab[y][x - 1] != 1)
			fill_the_path(tab, y, x - 1, w, h);
		if (tab[y + 1][x] != 1)
			fill_the_path(tab, y + 1, x, w, h);
	}
	else
		return ;
}
int	**matrice_all_paths(int **tab, int h, int w)
{
	int	x;
	int	x_cpy;
	int	y;

	x = -1;
	y = -1;
	x_cpy = 0;
	while (++y < h)
	{
		while (++x < w)
		{
			if (tab[y][x] == 'X')
			{
				fill_the_path2(tab, y, x, w, h);
				fill_the_path(tab, y, x, w, h);
			}
		}
		x = -1;
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
	tab = matrice_cpy_for_path(vars);
	while (++y < vars->height)
	{
		while (++x < vars->width)
			if (tab[y][x] == 'P')
				tab[y][x] = 'X';
		x = -1;
	}
	tab = matrice_all_paths(tab, vars->height, vars->width);
	tab = matrice_all_paths(tab, vars->height, vars->width);
	y = -1;
	while (++y < vars->height)
	{
		x = -1;
		while (++x < vars->width)
			if (tab[y][x] == 'C' || tab[y][x] == 'E')
				return (0);
	}
	return (1);
}

/* 


	while (++y < vars->height)
	{
		while (++x < vars->width)
			if (tab[y][x] == 'C' || tab[y][x] == 'E')
				return (0);
		x = -1;
	}

		while (++x < vars->width)
		{
			if (tab[y][x] == 1 || tab[y][x] == 0)
				printf("%d ", tab[y][x]);
			else
				printf("%c ", tab[y][x]);
			// if (tab[y][x] == 'C' || tab[y][x] == 'E')
			// 	return (0);
		}
		printf("\n");
 */