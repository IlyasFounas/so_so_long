/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:10:07 by marvin            #+#    #+#             */
/*   Updated: 2025/01/04 17:55:03 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// first creat wall function
int	create_img(t_data img, int i, int	j, int color)
{
	int	k;
	int	q;
	t_data img;

	k = i;	
	if (j == 0)
		j++;
	q = (j * 60) - 60;
	// img.img = mlx_new_image(mlx, window_size->width * 60, window_size->height
	// 		* 60);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 		&img.endian);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	while (i < k + 60)
	{
		while (q < j * 60)
		{
			my_mlx_pixel_put(&img, i, q, color);
			q++;
		}
		q = (j * 60) - 60;
		i++;
	}
	return (i);
}

void	create_map(t_data img, t_tab *matrice, t_size *window_size, void *mlx, void *mlx_win)
{
	t_tab	*ptr_to_matrice;
	int		i;
	int		j;
	int		axe_x;

	i = 0;
	j = 0;
	axe_x = 0;
	while (matrice)
	{
		ptr_to_matrice = matrice;
		while (i < window_size->width)
		{
			if (ptr_to_matrice->tab != NULL)
			{
				if (ptr_to_matrice->tab[i] != 1 && ptr_to_matrice->tab[i] != 0)
					ptr_to_matrice->tab[i] += 48;
				if (ptr_to_matrice->tab[i] == 1)
					axe_x = create_img(img, axe_x, j, 0xFFFFFFFF);
				else if (ptr_to_matrice->tab[i] == 0)
					axe_x = create_img(img, axe_x, j, 0x0000FFFF);
				else if (ptr_to_matrice->tab[i] == 'C')
					axe_x = create_img(img, axe_x, j, 0x0000F145);
				else if (ptr_to_matrice->tab[i] == 'P')
					axe_x = create_img(img, axe_x, j, 0x12456789);
				else if (ptr_to_matrice->tab[i] == 'E')
					axe_x = create_img(img, axe_x, j, 0xFFFFF145);
			}
			i++;
		}
		j++;
		axe_x = 0;
		i = 0;
		matrice = matrice->next;
	}
	free_matrice(ptr_to_matrice);
}

void	window_handling(t_size *window_size, t_tab *matrice)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, window_size->width * 60, window_size->height
			* 60, "SO_LONG");
	img.img = mlx_new_image(mlx, window_size->width * 60, window_size->height
			* 60);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	create_map(img, matrice, window_size, mlx, mlx_win);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
