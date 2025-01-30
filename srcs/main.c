/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:43:09 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/30 11:07:40 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
					* img_width, (y)*img_height);
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
		ft_printf("You finished the game with %d steps\n", deplacement_count);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	while (++y < vars->height)
		free(vars->matrice_of_m[y]);
	free(vars->matrice_of_m);
	if (hero_axes)
		free(hero_axes);
	free(vars->mlx);
	exit(0);
}

int	check_the_map_extension(char *s)
{
	if (ft_strncmp(s, "./so_long", ft_strlen(s)) == 0)
		return (write(2, "\n\n>> A map is required to run so_long <<\n\n",
				ft_strlen("\n\n>> A map is required to run so_long <<\n\n")),
			0);
	if (ft_strncmp(ft_strchr(s, '.'), ".ber", 4) != 0 || ft_strchr(ft_strchr(s,
				'.') + 1, '.') != NULL)
		return (write(2, "\n\n>> This map isn't a .ber extenson <<\n\n",
				ft_strlen("\n\n>> This map isn't a .ber extenson <<\n\n")), 0);
	if (ft_strncmp(s, "maps/", 5) != 0)
		return (write(2, "\n\n>> You forgot the 'maps/' path <<\n\n",
				ft_strlen("\n\n>> You forgot the 'maps/' path <<\n\n")), 0);
	return (1);
}

int	main(int arv, char **arg)
{
	int		fd;
	char	*path;
	t_tab	*matrice;
	t_tab	*ptr_matrice;
	t_vars	vars;

	if (check_the_map_extension(arg[arv - 1]) == 0)
		return (0);
	vars.matrice_of_m = NULL;
	vars.height = 0;
	vars.width = 0;
	matrice = (t_tab *)malloc(sizeof(t_tab));
	matrice->tab = NULL;
	matrice->next = NULL;
	ptr_matrice = matrice;
	path = ft_strdup(arg[arv - 1]);
	if (!path)
		return (free(path), 0);
	fd = open(path, O_RDONLY);
	parsing_handling(fd, path, matrice, &vars);
	close(fd);
	if (is_the_map_correct(ptr_matrice, &vars) == 0 || fd == -1)
		exit(0);
	create_window(&vars);
}
