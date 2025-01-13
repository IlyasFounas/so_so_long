/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:28:06 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/13 15:35:05 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

void	manage_enemy(t_vars *vars)
{
	int		y;
	int		x;
	t_axes	*pos_hero = malloc(sizeof(t_axes *));
	t_axes	*pos_enemie = malloc(sizeof(t_axes *));

	y = 0;
	x = -1;
	while (++y <= vars->height)
	{
		while (++x < vars->width)
		{
			if (vars->matrice_of_m[y][x] == 'A')
			{
				pos_enemie->axe_x = x;
				pos_enemie->axe_y = y;
			}
			if (vars->matrice_of_m[y][x] == 'P')
			{
				pos_hero->axe_x = x;
				pos_hero->axe_y = y;
			}
		}
		x = 0;
	}
    // ft_printf("%d %d \n", pos_enemie->axe_x, pos_hero->axe_x);
	free(pos_hero);
	free(pos_enemie);
}
