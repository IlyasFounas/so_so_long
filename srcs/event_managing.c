/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:25:20 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/08 18:25:35 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

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
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Grass1.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, hero_axes->axe_y * img_height);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Hero.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				(hero_axes->axe_x + 1) * img_width, hero_axes->axe_y
				* img_height);
		}
	}
	if (keycode == 115)
	{
		hero_axes = find_t_axes(vars, "DOWN");
		if (hero_axes->yes_or_no == 1)
		{
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Grass1.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, hero_axes->axe_y * img_height);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Hero.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, (hero_axes->axe_y + 1)
				* img_height);
		}
	}
	if (keycode == 119)
	{
		hero_axes = find_t_axes(vars, "UP");
		if (hero_axes->yes_or_no == 1)
		{
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Grass1.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, hero_axes->axe_y * img_height);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Hero.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, (hero_axes->axe_y - 1)
				* img_height);
		}
	}
	if (keycode == 97)
	{
		hero_axes = find_t_axes(vars, "LEFT");
		if (hero_axes->yes_or_no == 1)
		{
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Grass1.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				hero_axes->axe_x * img_width, hero_axes->axe_y * img_height);
			vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Hero2.xpm",
					&img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->hero,
				(hero_axes->axe_x - 1) * img_width, hero_axes->axe_y
				* img_height);
		}
	}
	if (hero_axes->yes_or_no == 1)
	{
		deplacement_count++;
		printf("%d\n", deplacement_count);
	}
	if (finished_or_not(vars) == 1)
		allow_to_exit(vars, "assets/Exit2.xpm");
	return (1);
}
