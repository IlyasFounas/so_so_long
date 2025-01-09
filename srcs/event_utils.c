/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:59:48 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/09 17:24:22 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

int	finished_or_not(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (y < vars->height)
	{
		while (x < vars->width - 1)
		{
			if (vars->matrice_of_m[y][x] == 'C')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	allow_to_exit(t_vars *vars, char *path)
{
	int		x;
	int		y;
	void	*exit;
	int		img_width;
	int		img_height;

	x = 0;
	y = 1;
	while (y < vars->height)
	{
		while (x < vars->width - 1)
		{
			if (vars->matrice_of_m[y][x] == 'E')
			{
				exit = mlx_xpm_file_to_image(vars->mlx, path,
						&img_width, &img_height);
				mlx_put_image_to_window(vars->mlx, vars->win, exit, x
					* img_width, (y - 1) * img_height);
				vars->matrice_of_m[y][x] = 'e';
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	finish_the_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
