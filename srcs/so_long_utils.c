/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:47 by ifounas           #+#    #+#             */
/*   Updated: 2025/02/06 12:10:34 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrice(t_tab *matrice)
{
	t_tab	*tmp;

	while (matrice)
	{
		tmp = matrice->next;
		if (matrice->tab)
			free(matrice->tab);
		free(matrice);
		matrice = tmp;
	}
}

int	manage_error_map_parsing(char *line, char *path, t_tab *matrice)
{
	free(line);
	free(path);
	free_matrice(matrice);
	return (write(2, "\n\n>> Error this map isn't a rectangle <<\n\n",
			ft_strlen("\n\n>> Error this map isn't a rectangle <<\n\n")), 0);
}

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

	x = -1;
	y = -1;
	while (++y < vars->height)
	{
		while (++x < vars->width)
		{
			if (vars->matrice_of_m[y][x] == 'E')
			{
				exit = mlx_xpm_file_to_image(vars->mlx, path, &img_width,
						&img_height);
				mlx_put_image_to_window(vars->mlx, vars->win, exit, x
					* img_width, (y * img_height));
				mlx_destroy_image(vars->mlx, exit);
				vars->matrice_of_m[y][x] = 'e';
			}
		}
		x = -1;
	}
}

void	finish_the_game(t_vars *vars, int deplacement_count, t_axes *hero_axes)
{
	int	y;

	y = -1;
	if (deplacement_count > 0)
		ft_printf("\n>> You finished the game in %d steps <<\n\n",
			deplacement_count);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	while (++y < vars->height)
		free(vars->matrice_of_m[y]);
	free(vars->matrice_of_m);
	if (hero_axes)
		free(hero_axes);
	if (vars->win)
		free(vars->mlx);
	exit(0);
}
