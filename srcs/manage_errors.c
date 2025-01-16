/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:43:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/16 11:37:34 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

/*

//////////////////PARTIE OBLIGATOIRE///////////////////////

remplacer les assets

leaks

*/

static int	verif_border_wall(t_vars *vars, int y, int x)
{
	if (vars->matrice_of_m[y][0] != 1 || vars->matrice_of_m[y][vars->width
		- 1] != 1)
		return (0);
	while (++x < vars->width)
	{
		if (y == 0 || y == vars->height)
			if (vars->matrice_of_m[y][x] != 1)
				return (0);
	}
	return (1);
}

static int	verif_nb_characters(t_vars *vars, int y, int x)
{
	static int	exitNDstart;
	static int	item;
	int			c;

	if (!exitNDstart)
		exitNDstart = 0;
	if (!item)
		item = 0;
	while (++x < vars->width)
	{
		if (vars->matrice_of_m[y][x] != 0 && vars->matrice_of_m[y][x] != 1)
			vars->matrice_of_m[y][x] += 48;
		c = vars->matrice_of_m[y][x];
		if (c == 'E' || c == 'P')
			exitNDstart++;
		if (c == 'C')
			item++;
		if (c != 1 && c != 0 && c != 'P' && c != 'E' && c != 'S' && c != 'A'
			&& c != 'C')
			return (0);
	}
	if (y == vars->height)
		if ((exitNDstart > 2 || exitNDstart < 2) || item < 1)
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
		while (x < window_size->width)
		{
			if (ptr_matrice->tab)
				vars->matrice_of_m[y - 1][x] = ptr_matrice->tab[x];
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

	y = -1;
	create_array2D(matrice, window_size, vars);
	vars->height = window_size->height;
	vars->width = window_size->width;
	while (++y < vars->height)
	{
		if (verif_nb_characters(vars, y, -1) == 0 || vars->height >= vars->width
			|| verif_border_wall(vars, y, -1) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	if (is_the_path_valid_or_not(vars) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}
