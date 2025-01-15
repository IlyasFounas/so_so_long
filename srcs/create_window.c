/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:22:08 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/15 19:28:11 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

static int	create_object(t_vars *vars, char *path, int axe_x, int axe_y)
{
	int		img_width;
	int		img_height;
	void	*img_void;

	img_void = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
	if (!img_void)
		return (img_width);
	mlx_put_image_to_window(vars->mlx, vars->win, img_void, axe_x, (axe_y - 1)
		* img_height);
	if (ft_strncmp(path, "assets/Hero.xpm", ft_strlen("assets/Hero.xpm")) == 0)
		vars->hero = img_void;
	return (img_width);
}

static int	verif_object(int axe_x, int axe_y, t_vars *vars, int i)
{
	if (vars->matrice_of_m[axe_y][i] == 1)
		axe_x += create_object(vars, "assets/Trees.xpm", axe_x, axe_y);
	else if (vars->matrice_of_m[axe_y][i] == 0)
		axe_x += create_object(vars, "assets/Grass1.xpm", axe_x, axe_y);
	else if (vars->matrice_of_m[axe_y][i] == 'C')
		axe_x += create_object(vars, "assets/Item.xpm", axe_x, axe_y);
	else if (vars->matrice_of_m[axe_y][i] == 'P')
		axe_x += create_object(vars, "assets/Hero.xpm", axe_x, axe_y);
	else if (vars->matrice_of_m[axe_y][i] == 'E')
		axe_x += create_object(vars, "assets/Exit.xpm", axe_x, axe_y);
	else if (vars->matrice_of_m[axe_y][i] == 'A')
		axe_x += create_object(vars, "assets/Enemy.xpm", axe_x, axe_y);
	return (axe_x);
}

static void	create_map(t_size *window_size, t_vars *vars)
{
	int	axe_y;
	int	axe_x;
	int	i;

	axe_x = 0;
	i = 0;
	axe_y = 0;
	while (axe_y <= window_size->height)
	{
		while (i < window_size->width)
		{
			axe_x = verif_object(axe_x, axe_y, vars, i);
			i++;
		}
		i = 0;
		axe_x = 0;
		axe_y++;
	}
	vars->width = window_size->width;
	vars->height = window_size->height;
}

int mouse_hook(int keycode)
{
	exit (0);
	return (keycode);
}

void	create_window(t_size *window_size, t_vars *vars)
{
	void	*img_ptr;
	int		img_w;
	int		img_h;

	vars->mlx = mlx_init();
	// malloc
	img_ptr = mlx_xpm_file_to_image(vars->mlx, "assets/Grass1.xpm", &img_w,
			&img_h);
	if (!img_ptr)
		return ;
	vars->win = mlx_new_window(vars->mlx, window_size->width * img_w,
			window_size->height * img_h, "SO_LONG");
	// malloc
	create_map(window_size, vars);
	
	manage_enemy(vars);
	mlx_hook(vars->win, 2, 1L << 0, manage_events, vars);
	mlx_hook(vars->win, 17, 1L << 17, mouse_hook, vars);
	mlx_loop(vars->mlx);
}
