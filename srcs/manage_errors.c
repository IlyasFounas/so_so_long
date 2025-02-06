/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:43:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/06 12:08:13 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	verif_border_wall(t_vars *vars, int y, int x)
{
	if (vars->matrice_of_m[y][0] != 1 || vars->matrice_of_m[y][vars->width
		- 1] != 1)
		return (0);
	while (++x < vars->width)
	{
		if (y == 0 || y == vars->height - 1)
			if (vars->matrice_of_m[y][x] != 1)
				return (0);
	}
	return (1);
}

static int	verif_nb_characters(t_vars *vars, int y, int x)
{
	static int	exitstart;
	static int	item;
	int			c;

	if (!exitstart)
		exitstart = 0;
	if (!item)
		item = 0;
	while (++x < vars->width)
	{
		if (vars->matrice_of_m[y][x] != 0 && vars->matrice_of_m[y][x] != 1)
			vars->matrice_of_m[y][x] += 48;
		c = vars->matrice_of_m[y][x];
		if (c == 'E' || c == 'P')
			exitstart++;
		if (c == 'C')
			item++;
		if (c != 1 && c != 0 && c != 'P' && c != 'E' && c != 'C')
			return (0);
	}
	if (y == vars->height - 1)
		if ((exitstart > 2 || exitstart < 2) || item < 1)
			return (0);
	return (1);
}

static void	create_array_2d(t_tab *matrice, t_vars *vars)
{
	int		y;
	int		x;
	t_tab	*ptr_matrice;

	y = 0;
	x = -1;
	vars->matrice_of_m = malloc((vars->height) * sizeof(int *));
	if (!vars->matrice_of_m)
		return ;
	while (matrice)
	{
		ptr_matrice = matrice;
		if (ptr_matrice->tab)
		{
			vars->matrice_of_m[y] = malloc((vars->width) * sizeof(int));
			if (!vars->matrice_of_m[y])
				return ;
			while (++x < vars->width)
				vars->matrice_of_m[y][x] = ptr_matrice->tab[x];
			x = -1;
			y++;
		}
		matrice = matrice->next;
	}
}

int	is_the_map_correct(t_tab *matrice, t_vars *vars)
{
	int	y;

	y = -1;
	create_array_2d(matrice, vars);
	free_matrice(matrice);
	while (++y < vars->height)
	{
		if (verif_nb_characters(vars, y, -1) == 0 || verif_border_wall(vars, y,
				-1) == 0)
		{
			write(2, "\n\n>> Error with the formatting of the map <<\n\n",
				ft_strlen("\n\n>> Error with the formatting of the map <<\n\n")
				);
			while (--vars->height >= 0)
				free(vars->matrice_of_m[vars->height]);
			free(vars->matrice_of_m);
			return (0);
		}
	}
	if (ft_flood_fill(vars) == 0)
		return (write(2, "\n\n>> Error no path can finish the map <<\n\n",
				ft_strlen("\n\n>> Error no path can finish the map <<\n\n")),
			0);
	return (1);
}
