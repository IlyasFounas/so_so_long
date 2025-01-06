/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:21:50 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/06 18:01:34 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

// by t_axes find what object the hero is going on
// int find_object_by_t_axes()
// {
    
// }

// where the hero going
t_axes *find_t_axes(t_vars *vars)
{
    int x;
    int y;
    t_axes *pos;
    
    x = 0;
    y = 0;
    while(y < vars->height)
    {
        while (x < vars->width)
        {
            if (vars->matrice_of_m[x][y] = 'P')
            {
                pos->axe_x = x;
                pos->axe_y = x;
            }            
        }
        y++;
    }
}

int	manage_event(int keycode, t_vars *vars)
{
	static int deplacement_count;
	int		img_width;
	int		img_height;
    t_axes  *hero_axes;
    
	if (!deplacement_count)
		deplacement_count = 0;
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(keycode);
	}
	if (keycode == 100)
	{
        mlx_destroy_image(vars->mlx, vars->hero);
        vars->hero = mlx_xpm_file_to_image(vars->mlx, "assets/Grass1.xpm", &img_width,
			&img_height);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->hero, 0, 0);
		deplacement_count++;
		printf("%d\n", deplacement_count);
	}
	else if (keycode == 115)
	{
		deplacement_count++;
		printf("%d\n", deplacement_count);
	}
	else if (keycode == 119)
	{
		deplacement_count++;
		printf("%d\n", deplacement_count);
	}
	else if (keycode == 97)
	{
		deplacement_count++;
		printf("%d\n", deplacement_count);
	}
	return (1);
}
