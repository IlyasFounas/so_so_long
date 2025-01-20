/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:15:23 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/20 12:03:43 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

static int	**matrice_cpy_for_path(t_vars *vars)
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
			tab[y2][x2] = vars->matrice_of_m[y2][x2];
		x2 = -1;
	}
	return (tab);
}

static void	path_up_and_right(int **tab, int y, int x, int w, int h)
{
	if (tab[y][x] != 1 && tab[y][x] != 2)
	{
		if (tab[y][x] == 'E')
		{
			if (tab[y - 1][x] == 'C' && tab[y - 2][x] == 1 && tab[y - 1][x
				+ 1] == 1 && tab[y - 1][x - 1] == 1)
				tab[y - 1][x] = 2;
			if (tab[y][x + 1] == 'C' && tab[y][x + 2] == 1 && tab[y - 1][x
				+ 1] == 1 && tab[y + 1][x - 1] == 1)
				tab[y][x + 1] = 2;
			tab[y][x] = 'X';
			return ;
		}
		tab[y][x] = 'X';
		if (tab[y - 1][x] != 1)
			path_up_and_right(tab, y - 1, x, w, h);
		if (tab[y][x + 1] != 1)
			path_up_and_right(tab, y, x + 1, w, h);
	}
	else
		return ;
}

static void	path_down_and_left(int **tab, int y, int x, int w, int h)
{
	if (tab[y][x] != 1 && tab[y][x] != 2)
	{
		if (tab[y][x] == 'E')
		{
			if (tab[y + 1][x] == 'C' && tab[y + 2][x] == 1 && tab[y + 1][x
				+ 1] == 1 && tab[y + 1][x - 1] == 1)
				tab[y + 1][x] = 2;
			if (tab[y][x - 1] == 'C' && tab[y][x - 2] == 1 && tab[y - 1][x
				- 1] == 1 && tab[y + 1][x - 1] == 1)
				tab[y][x + 1] = 2;
			tab[y][x] = 'X';
			return ;
		}
		tab[y][x] = 'X';
		if (tab[y][x - 1] != 1)
			path_down_and_left(tab, y, x - 1, w, h);
		if (tab[y + 1][x] != 1)
			path_down_and_left(tab, y + 1, x, w, h);
	}
	else
		return ;
}
static int	**matrice_all_paths(int **tab, int h, int w)
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
				path_up_and_right(tab, y, x, w, h);
				path_down_and_left(tab, y, x, w, h);
			}
		}
		x = -1;
	}
	return (tab);
}

int	ft_flood_fill(t_vars *vars)
{
	int	y;
	int	x;
	int	**tab;

	y = -1;
	tab = matrice_cpy_for_path(vars);
	while (++y < vars->height)
	{
		x = -1;
		while (++x < vars->width)
			if (tab[y][x] == 'P')
				tab[y][x] = 'X';
	}
	tab = matrice_all_paths(tab, vars->height, vars->width);
	tab = matrice_all_paths(tab, vars->height, vars->width);
	y = -1;
	while (++y < vars->height)
	{
		x = -1;
		while (++x < vars->width)
			if (tab[y][x] == 'C' || tab[y][x] == 'E' || tab[y][x] == 2)
				return (0);
		free(tab[y]);
	}
	return (free(tab), 1);
}
