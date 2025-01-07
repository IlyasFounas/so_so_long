/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:21:50 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/07 18:52:03 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

// by t_axes find what object the hero is going on
// int find_object_by_t_axes()
// {

// }

// where the hero going
t_axes	*find_t_axes(t_vars *vars, char *path)
{
	int		x;
	int		y;
	t_axes	*pos;

	pos = (t_axes *)malloc(sizeof(t_axes));
	if (!pos)
		return (NULL);
	x = 0;
	y = 1;
	while (y < vars->height)
	{
		while (x < vars->width - 1)
		{
			printf("%d %d %d \n",y , x,  vars->matrice_of_m[y][x]);
			if (vars->matrice_of_m[y][x] == 'P')
			{
				if (ft_strncmp("UP", path, ft_strlen("UP")) == 0)
				{
					if (y > 0)
					{
						if (vars->matrice_of_m[y - 1][x] == 1)
							pos->yes_or_no = 0;
						else
							pos->yes_or_no = 1;	
					}
					else
						pos->yes_or_no = 0;
				}
				else if (ft_strncmp("DOWN", path, ft_strlen("DOWN")) == 0)
				{
					if (y < vars->height)
					{
						if (vars->matrice_of_m[y + 1][x] == 1)
							pos->yes_or_no = 0;
						else
							pos->yes_or_no = 1;
					}
					else
						pos->yes_or_no = 0;
				}
				else if (ft_strncmp("LEFT", path, ft_strlen("LEFT")) == 0)
				{
					if (x > 0)
					{
						if (vars->matrice_of_m[y][x - 1] == 1)
							pos->yes_or_no = 0;
						else
							pos->yes_or_no = 1;
					}
					else
						pos->yes_or_no = 0;
				}
				else if (ft_strncmp("RIGHT", path, ft_strlen("RIGHT")) == 0)
				{
					if (x < vars->width)
					{
						if (vars->matrice_of_m[y][x + 1] == 1)
							pos->yes_or_no = 0;
						else
							pos->yes_or_no = 1;
					}
					else
						pos->yes_or_no = 0;
				}
				pos->axe_x = x;
				pos->axe_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (pos);
}

int	manage_event(int keycode, t_vars *vars)
{
	static int	deplacement_count;
	int			img_width;
	int			img_height;
	t_axes		*hero_axes;

	if (!deplacement_count)
		deplacement_count = 0;
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(keycode);
	}
	
	if (keycode == 100)
	{
		hero_axes = find_t_axes(vars, "RIGHT");
		if (hero_axes->yes_or_no == 1)
		{
			mlx_destroy_image(vars->mlx, vars->hero);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Grass1.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, hero_axes->axe_y * img_height);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Hero.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, (hero_axes->axe_y + 1)
				* img_height);
			deplacement_count++;
			printf("%d\n", deplacement_count);
		}
	}
	if (keycode == 115)
	{
		hero_axes = find_t_axes(vars, "DOWN");
		if (hero_axes->yes_or_no == 1)
		{
			mlx_destroy_image(vars->mlx, vars->hero);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Grass1.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, hero_axes->axe_y * img_height);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Hero.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, (hero_axes->axe_y - 1)
				* img_height);
			deplacement_count++;
			printf("%d\n", deplacement_count);
		}
	}
	if (keycode == 119)
	{
		hero_axes = find_t_axes(vars, "UP");
		if (hero_axes->yes_or_no == 1)
		{
			mlx_destroy_image(vars->mlx, vars->hero);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Grass1.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, hero_axes->axe_y * img_height);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Hero.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				(hero_axes->axe_x - 1) * img_width, (hero_axes->axe_y)
				* img_height);
			deplacement_count++;
			printf("%d\n", deplacement_count);
		}
	}
	if (keycode == 97)
	{
		hero_axes = find_t_axes(vars, "LEFT");
		if (hero_axes->yes_or_no == 1)
		{
			mlx_destroy_image(vars->mlx, vars->hero);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Grass1.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, hero_axes->axe_y * img_height);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Hero.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				(hero_axes->axe_x + 1) * img_width, (hero_axes->axe_y + 1)
				* img_height);
			deplacement_count++;
			printf("%d\n", deplacement_count);
		}
	}
	// free(hero_axes->axe_x);
	// free(hero_axes->axe_y);
	// free(hero_axes->yes_or_no);
	return (1);
}
