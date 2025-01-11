/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:43:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/11 18:09:10 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

/*

chemin valide

1 0 P E C A

*/

static int	verif_border_wall(t_vars *vars, int y, int x)
{
	if (y > 1)
	{
		if (vars->matrice_of_m[y][0] != 1 || vars->matrice_of_m[y][vars->width - 1] != 1)
			return (0);
	}
	while (++x < vars->width)
	{
		if (y == 1 || y == vars->height)
			if (vars->matrice_of_m[y][x] != 1)
				return (0);
	}
	return (1);
}

static int	verif_nb_characters(t_vars *vars, int y, int x)
{
	static int	exit;
	static int	item;
	static int	start;

	if (!exit)
		exit = 0;
	if (!item)
		item = 0;
	if (!start)
		start = 0;
	while (++x < vars->width)
	{
		if (vars->matrice_of_m[y][x] != 0 && vars->matrice_of_m[y][x] != 1)
			vars->matrice_of_m[y][x] += 48;
		if (vars->matrice_of_m[y][x] == 'E')
			exit++;
		if (vars->matrice_of_m[y][x] == 'C')
			item++;
		if (vars->matrice_of_m[y][x] == 'P')
			start++;
	}
	if (y == vars->height)
		if (exit > 1 || item < 1 || start > 1)
			return (0);
	return (1);
}

static void	create_array2D(t_tab *matrice, t_size *window_size, t_vars *vars)
{
	int		y;
	int		x;
	t_tab	*ptr_matrice;

	y = 0;
	x = 0;
	vars->matrice_of_m = malloc((window_size->height + 1) * sizeof(int *));
	if (!vars->matrice_of_m)
		return ;
	while (matrice)
	{
		ptr_matrice = matrice;
		vars->matrice_of_m[y] = malloc((window_size->width) * sizeof(int));
		if (!vars->matrice_of_m[y])
			return ;
		while (x <= window_size->width)
		{
			if (ptr_matrice->tab)
				vars->matrice_of_m[y][x] = ptr_matrice->tab[x];
			x++;
		}
		x = 0;
		y++;
		matrice = matrice->next;
	}
}

int	is_the_map_correct(t_tab *matrice, t_size *window_size, t_vars *vars)
{
	int	y;

	y = 0;
	create_array2D(matrice, window_size, vars);
	vars->height = window_size->height;
	vars->width = window_size->width;
	while (y <= vars->height)
	{
		if (verif_nb_characters(vars, y, -1) == 0 || vars->height >= vars->width
			|| verif_border_wall(vars, y, -1) == 0)
		{
			printf("Error\n");
			return (0);
		}
		y++;
	}
	return (1);
}
