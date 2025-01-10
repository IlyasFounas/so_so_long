/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:25:20 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/10 11:37:55 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"

static t_axes	*right_event(t_vars *vars)
{
	t_axes	*hero_axes;
	int		img_width;
	int		img_height;

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
			(hero_axes->axe_x + 1) * img_width, hero_axes->axe_y * img_height);
	}
	return (hero_axes);
}

static t_axes	*left_event(t_vars *vars)
{
	t_axes	*hero_axes;
	int		img_width;
	int		img_height;

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
			(hero_axes->axe_x - 1) * img_width, hero_axes->axe_y * img_height);
	}
	return (hero_axes);
}

static t_axes	*down_event(t_vars *vars)
{
	t_axes	*hero_axes;
	int		img_width;
	int		img_height;

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
			hero_axes->axe_x * img_width, (hero_axes->axe_y + 1) * img_height);
	}
	return (hero_axes);
}

static t_axes	*up_event(t_vars *vars)
{
	t_axes	*hero_axes;
	int		img_width;
	int		img_height;

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
			hero_axes->axe_x * img_width, (hero_axes->axe_y - 1) * img_height);
	}
	return (hero_axes);
}

int	manage_event(int keycode, t_vars *vars)
{
	static int	deplacement_count;
	t_axes		*hero_axes;

	if (!deplacement_count)
		deplacement_count = 0;
	if (keycode == 65307)
		finish_the_game(vars);
	if (keycode == 100)
		hero_axes = right_event(vars);
	if (keycode == 115)
		hero_axes = down_event(vars);
	if (keycode == 119)
		hero_axes = up_event(vars);
	if (keycode == 97)
		hero_axes = left_event(vars);
	if (hero_axes->yes_or_no == 1)
	{
		deplacement_count++;
		printf("%d\n", deplacement_count);
	}
	if (finished_or_not(vars) == 1)
		allow_to_exit(vars, "assets/Exit2.xpm");
	return (1);
}
