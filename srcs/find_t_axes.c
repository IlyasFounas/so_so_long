/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_t_axes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:21:50 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/06 12:00:35 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	yes_or_no_up_down(t_vars *vars, int y, int x, int up_down)
{
	if (up_down == 1)
	{
		if (y > 0)
		{
			if (vars->matrice_of_m[y - 1][x] == 1 || vars->matrice_of_m[y
				- 1][x] == 'E')
				return (0);
			vars->matrice_of_m[y][x] = 0;
			vars->matrice_of_m[y - 1][x] = 'P';
			return (1);
		}
		return (0);
	}
	if (y < vars->height)
	{
		if (vars->matrice_of_m[y + 1][x] == 1 || vars->matrice_of_m[y
			+ 1][x] == 'E')
			return (0);
		vars->matrice_of_m[y][x] = 0;
		vars->matrice_of_m[y + 1][x] = 'P';
		return (1);
	}
	return (0);
}

static int	yes_or_no_left_right(t_vars *vars, int y, int x, int left_right)
{
	if (left_right == 1)
	{
		if (x > 0)
		{
			if (vars->matrice_of_m[y][x - 1] == 1 || vars->matrice_of_m[y][x
				- 1] == 'E')
				return (0);
			vars->matrice_of_m[y][x] = 0;
			vars->matrice_of_m[y][x - 1] = 'P';
			return (1);
		}
		return (0);
	}
	if (x < vars->width)
	{
		if (vars->matrice_of_m[y][x + 1] == 1 || vars->matrice_of_m[y][x
			+ 1] == 'E')
			return (0);
		vars->matrice_of_m[y][x] = 0;
		vars->matrice_of_m[y][x + 1] = 'P';
		return (1);
	}
	return (0);
}

static int	axes_by_key_pressed(t_vars *vars, char *path, int y, int x)
{
	if (ft_strncmp("UP", path, ft_strlen("UP")) == 0)
	{
		if (vars->matrice_of_m[y - 1][x] == 'e')
			return (2);
		return (yes_or_no_up_down(vars, y, x, 1));
	}
	else if (ft_strncmp("DOWN", path, ft_strlen("DOWN")) == 0)
	{
		if (vars->matrice_of_m[y + 1][x] == 'e')
			return (2);
		return (yes_or_no_up_down(vars, y, x, 0));
	}
	else if (ft_strncmp("LEFT", path, ft_strlen("LEFT")) == 0)
	{
		if (vars->matrice_of_m[y][x - 1] == 'e')
			return (2);
		return (yes_or_no_left_right(vars, y, x, 1));
	}
	else if (ft_strncmp("RIGHT", path, ft_strlen("RIGHT")) == 0)
	{
		if (vars->matrice_of_m[y][x + 1] == 'e')
			return (2);
		return (yes_or_no_left_right(vars, y, x, 0));
	}
	return (0);
}

t_axes	*find_t_axes(t_vars *vars, char *path)
{
	int		x;
	int		y;
	t_axes	*pos;

	pos = (t_axes *)malloc(sizeof(t_axes));
	if (!pos)
		return (NULL);
	x = -1;
	y = -1;
	while (++y < vars->height)
	{
		while (++x < vars->width)
		{
			if (vars->matrice_of_m[y][x] == 'P')
			{
				pos->yes_or_no = axes_by_key_pressed(vars, path, y, x);
				pos->axe_x = x;
				pos->axe_y = y;
				return (pos);
			}
		}
		x = 0;
	}
	return (pos);
}
