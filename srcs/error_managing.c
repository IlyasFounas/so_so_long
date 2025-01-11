/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:43:17 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/11 16:05:43 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

/*

1 exit

1 item minimum

1 start

forme rectangulaire

encadre par des murs

chemin valide

message d'ereur : "Error\n"

1 0 P E C A

 */

static void	create_array2D(t_tab *ptr_matrice, t_size *window_size, t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	vars->matrice_of_m = malloc((window_size->height + 1) * sizeof(int *));
	if (!vars->matrice_of_m)
		return ;
	while (ptr_matrice)
	{
		vars->matrice_of_m[y] = malloc((window_size->height + 1) * sizeof(int *));
		if (!vars->matrice_of_m[y])
			return ;
		while (x < window_size->width)
		{
			vars->matrice_of_m[y][x] = ptr_matrice->tab[x];
			x++;
		}
		x = 0;
		y++;
	}
}

int	is_the_map_correct(t_tab *ptr_matrice, t_size *window_size, t_vars *vars)
{

	create_array2D(ptr_matrice, window_size, vars);
	if (!vars->matrice_of_m[0][0])
	{
		return (1);
	}
	return (0);
}
