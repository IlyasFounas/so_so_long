/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:43:09 by marvin            #+#    #+#             */
/*   Updated: 2025/01/11 16:00:27 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"

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

int	main(int arv, char **arg)
{
	int		fd;
	int		res_parsing;
	char	*path;
	t_size	window_size;
	t_tab	*matrice;
	t_tab	*ptr_matrice;
	
	matrice = (t_tab *)malloc(sizeof(t_tab));
	matrice->tab = NULL;
	matrice->next = NULL;
	ptr_matrice = matrice;
	window_size.height = 0;
	window_size.width = 0;
	path = ft_strjoin("maps/", arg[arv - 1]);
	if (!path)
		return (free(path), 0);
	fd = open(path, O_RDONLY);
	parsing_handling(fd, path, &window_size, matrice);
	free(path);
	if (is_the_map_correct(matrice, &window_size) == 0)
		exit(0);
	window_handling(&window_size, ptr_matrice);
}
