/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:22:08 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/07 18:54:05 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

int	create_object(t_vars *vars, char *path, int axe_x, int axe_y)
{
	int		img_width;
	int		img_height;
	void	*img_void;

	img_void = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
	if (!img_void)
		return (img_width);
	mlx_put_image_to_window(vars->mlx, vars->win, img_void, axe_x, (axe_y - 1)
		* img_width);
	if (ft_strncmp(path, "assets/Hero.xpm", ft_strlen("assets/Hero.xpm")) == 0)
		vars->hero = img_void;
	return (img_width);
}

int	verif_wich_object(int axe_x, int axe_y, t_vars *vars, t_tab *ptr_to_matrice,
		int i)
{
	if (ptr_to_matrice->tab[i] != 1 && ptr_to_matrice->tab[i] != 0)
		ptr_to_matrice->tab[i] += 48;
	if (ptr_to_matrice->tab[i] == 1)
		axe_x += create_object(vars, "assets/Trees.xpm", axe_x, axe_y);
	else if (ptr_to_matrice->tab[i] == 0)
		axe_x += create_object(vars, "assets/Grass1.xpm", axe_x, axe_y);
	else if (ptr_to_matrice->tab[i] == 'C')
		axe_x += create_object(vars, "assets/Item.xpm", axe_x, axe_y);
	else if (ptr_to_matrice->tab[i] == 'P')
	{
		axe_x += create_object(vars, "assets/Hero.xpm", axe_x, axe_y);
	}
	else if (ptr_to_matrice->tab[i] == 'E')
		axe_x += create_object(vars, "assets/Exit.xpm", axe_x, axe_y);
	return (axe_x);
}

void	create_map(t_tab *matrice, t_size *window_size, t_vars *vars)
{
	t_tab	*ptr_to_matrice;
	int		i;
	int		axe_y;
	int		axe_x;
	int		matrice2[window_size->width][window_size->height];

	i = 0;
	axe_y = 0;
	axe_x = 0;
	vars->matrice_of_m = malloc(window_size->height * sizeof(int));
	if (!vars->matrice_of_m)
		return ;
	while (matrice)
	{
		ptr_to_matrice = matrice;
		vars->matrice_of_m[axe_y] = malloc(window_size->width * sizeof(int));
		if (!vars->matrice_of_m)
			return ;
		while (i < window_size->width)
		{
			if (ptr_to_matrice->tab != NULL)
			{

				matrice2[axe_y][i] = ptr_to_matrice->tab[i];
				vars->matrice_of_m[axe_y][i] = ptr_to_matrice->tab[i];
				if (vars->matrice_of_m[axe_y][i] != 1 && vars->matrice_of_m[axe_y][i] != 0)
					vars->matrice_of_m[axe_y][i] += 48;
				axe_x = verif_wich_object(axe_x, axe_y, vars, ptr_to_matrice,
						i);
				// printf("%d %d %d\n", vars->matrice_of_m[axe_y][i], axe_y ,i );
			}
			i++;
		}
		axe_y++;
		axe_x = 0;
		i = 0;
		matrice = matrice->next;
	}
	// vars->matrice_of_m = malloc(window_size->height * sizeof(int));
	// if (!vars->matrice_of_m)
	// 	return ;
	// axe_y = 1;
	// while (axe_y < window_size->height)
	// {
		// vars->matrice_of_m[axe_y] = malloc(window_size->width * sizeof(int));
		// if (!vars->matrice_of_m)
		// 	return ;
	// 	while (i < window_size->width)
	// 	{
			// vars->matrice_of_m[axe_y][i] = matrice2[axe_y][i];
	// 		// printf("%d %d %d\n", matrice2[axe_y][i], axe_y ,i );
			// if (vars->matrice_of_m[axe_y][i] != 1 && vars->matrice_of_m[axe_y][i] != 0)
			// 	vars->matrice_of_m[axe_y][i] += 48;
	// 		i++;
	// 	}
	// 	i = 0;
	// 	axe_y++;
	// }
	vars->width = window_size->width;
	vars->height = window_size->height;
	free_matrice(ptr_to_matrice);
}

void	window_handling(t_size *window_size, t_tab *matrice)
{
	void	*img_ptr;
	int		img_w;
	int		img_h;
	t_vars	vars;

	vars.mlx = mlx_init();
	img_ptr = mlx_xpm_file_to_image(vars.mlx, "assets/Grass1.xpm", &img_w,
			&img_h);
	if (!img_ptr)
		return ;
	vars.win = mlx_new_window(vars.mlx, window_size->width * img_w,
			window_size->height * img_h, "SO_LONG");
	create_map(matrice, window_size, &vars);
	printf("here2\n");
	mlx_hook(vars.win, 2, 1L << 0, manage_event, &vars);
	mlx_loop(vars.mlx);
}
