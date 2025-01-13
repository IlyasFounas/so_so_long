/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_good_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:15:23 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/13 17:31:11 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

static void	forward(t_vars *vars, int y, int x, int *items2, int *exit)
{
    int yy;
    int xx;

    yy = y;
    xx = x;
	while (++yy <= vars->height)
	{
		while (++xx < vars->width)
		{
			if (vars->matrice_of_m[yy][xx] == 1)
				break ;
			if (vars->matrice_of_m[yy][xx] == 'C')
				items2++;
			if (vars->matrice_of_m[yy][xx] == 'E')
				exit++;
		}
		xx = x - 1;
	}
}

static void	backward(t_vars *vars, int y, int x, int *items2, int *exit)
{
    int yy;
    int xx;

    yy = y;
    xx = x;
	while (--yy <= 1)
	{
		while (--xx < 0)
		{
			if (vars->matrice_of_m[yy][xx] == 1)
				break ;
			if (vars->matrice_of_m[yy][xx] == 'C')
				items2++;
			if (vars->matrice_of_m[yy][xx] == 'E')
				exit++;
		}
		xx = x + 1;
	}
}

int	is_the_path_valid_or_not(t_vars *vars)
{
	int y;
	int x;
	int items;
	int items2;
	int exit;

	y = 0;
	x = -1;
	items = 0;
	items2 = 0;
	exit = 0;
	while (++y <= vars->height)
	{
		while (++x < vars->width)
		{
			if (vars->matrice_of_m[y][x] == 'C')
				items++;
			if (vars->matrice_of_m[y][x] == 'P')
			{
                forward(vars, y - 1, x - 1, &items2, &exit);
                backward(vars, y + 1, x + 1, &items2, &exit);
			}
		}
		x = -1;
	}
	if (items2 < items || exit < 1)
		return (0);
	return (1);
}
