/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:15:23 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/20 17:29:27 by ifounas          ###   ########.fr       */
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

static int	fill_path(int **tab, int y, int x, int w, int h)
{
	static int exit;

	if (!exit)
		exit = 0;
	if ((y < 0 || y >= h) || (x < 0 || x >= w))
		return (exit);
	if ( tab[y][x] == 'E' )
		exit = 1;
	if (tab[y][x] == 'C' || tab[y][x] == 'P' || tab[y][x] == 0)
		tab[y][x] = 'X';
	else
		return (exit);
	fill_path(tab, y, x + 1, w, h);
	fill_path(tab, y, x - 1, w, h);
	fill_path(tab, y + 1, x, w, h);
	fill_path(tab, y - 1, x, w, h);
	return (exit);
}

static int	**matrice_all_paths(int **tab, int h, int w, int *exit)
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
			if (tab[y][x] == 'P')
			{
				*exit = fill_path(tab, y, x, w, h);
				return (tab);
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
	int	exit;

	y = -1;
	exit = 0;
	tab = matrice_cpy_for_path(vars);
	tab = matrice_all_paths(tab, vars->height, vars->width, &exit);
	y = -1;
	printf("%d \n", exit);
	while (++y < vars->height)
	{
		x = -1;
		while (++x < vars->width)
			if (tab[y][x] == 'C' || exit == 0)
				return (0);
		free(tab[y]);
	}
	return (free(tab), 1);
}
