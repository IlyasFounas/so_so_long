/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:10:07 by marvin            #+#    #+#             */
/*   Updated: 2025/01/05 20:22:26 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

// first creat wall function
// int	create_img(t_data img, int i, int	j, int color)
// {
// 	int	k;
// 	int	q;

// 	k = i;	
// 	if (j == 0)
// 		j++;
// 	q = (j * 60) - 60;

// 	while (i < k + 60)
// 	{
// 		while (q < j * 60)
// 		{
// 			my_mlx_pixel_put(&img, i, q, color);
// 			q++;
// 		}
// 		q = (j * 60) - 60;
// 		i++;
// 	}
// 	return (i);
// }

// void	create_map(t_data img, t_tab *matrice, t_size *window_size)
// {
// 	t_tab	*ptr_to_matrice;
// 	int		i;
// 	int		j;
// 	int		axe_x;

// 	i = 0;
// 	j = 0;
// 	axe_x = 0;
// 	while (matrice)
// 	{
// 		ptr_to_matrice = matrice;
// 		while (i < window_size->width)
// 		{
// 			if (ptr_to_matrice->tab != NULL)
// 			{
// 				if (ptr_to_matrice->tab[i] != 1 && ptr_to_matrice->tab[i] != 0)
// 					ptr_to_matrice->tab[i] += 48;
// 				if (ptr_to_matrice->tab[i] == 1)
// 					axe_x = create_img(img, axe_x, j, 0xFFFFFFFF);
// 				else if (ptr_to_matrice->tab[i] == 0)
// 					axe_x = create_img(img, axe_x, j, 0x0000FFFF);
// 				else if (ptr_to_matrice->tab[i] == 'C')
// 					axe_x = create_img(img, axe_x, j, 0x0000F145);
// 				else if (ptr_to_matrice->tab[i] == 'P')
// 					axe_x = create_img(img, axe_x, j, 0x12456789);
// 				else if (ptr_to_matrice->tab[i] == 'E')
// 					axe_x = create_img(img, axe_x, j, 0xFFFFF145);
// 			}
// 			i++;
// 		}
// 		j++;
// 		axe_x = 0;
// 		i = 0;
// 		matrice = matrice->next;
// 	}
// 	free_matrice(ptr_to_matrice);
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_img(int color, void *mlx, void *mlx_win, int axe_x, int axe_y)
{
	int	i;
	int	j;
	t_data img;
	
	i = 0;
	j = 0;
	img.img = mlx_new_image(mlx, 16, 16);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (i < 16)
	{
		while (j < 16)
		{
			my_mlx_pixel_put(&img, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, axe_x, (axe_y - 1)*60);
	return (i);
}

int	create_object(void *mlx, void *mlx_win , char *path, int axe_x, int axe_y)
{
	int img_width;
	int img_height;
	void *img_void;
	
	img_void = mlx_xpm_file_to_image(mlx, "assets/Grass1.xpm", &img_width, &img_height);
	if (!img_void)
		return (img_width);
	mlx_put_image_to_window(mlx, mlx_win, img_void, axe_x, (axe_y - 1)*img_width);
	img_void = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	if (!img_void)
		return (img_width);
	mlx_put_image_to_window(mlx, mlx_win, img_void, axe_x, (axe_y - 1)*img_width);
	return (img_width);
}

void	create_map(t_tab *matrice, t_size *window_size, void *mlx, void *mlx_win)
{
	t_tab	*ptr_to_matrice;
	int		i;
	int		axe_y;
	int		axe_x;

	i = 0;
	axe_y = 0;
	axe_x = 0;
	while (matrice)
	{
		ptr_to_matrice = matrice;
		while (i < window_size->width)
		{
			if (ptr_to_matrice->tab != NULL)
			{
				// if (ptr_to_matrice->tab[i] != 1 && ptr_to_matrice->tab[i] != 0)
				// 	ptr_to_matrice->tab[i] += 48;
				// if (ptr_to_matrice->tab[i] == 1)
				// 	axe_x += create_img(0xFFFFFFFF, mlx, mlx_win, axe_x, axe_y);
				// else if (ptr_to_matrice->tab[i] == 0)
				// 	axe_x += create_img(0x0000FFFF, mlx, mlx_win, axe_x, axe_y);
				// else if (ptr_to_matrice->tab[i] == 'C')
				// 	axe_x += create_img(0x0000F145, mlx, mlx_win, axe_x, axe_y);
				// else if (ptr_to_matrice->tab[i] == 'P')
				// 	axe_x += create_img(0x12456789, mlx, mlx_win, axe_x, axe_y);
				// else if (ptr_to_matrice->tab[i] == 'E')
				// 	axe_x += create_img(0xFFFFF145, mlx, mlx_win, axe_x, axe_y);
				if (ptr_to_matrice->tab[i] != 1 && ptr_to_matrice->tab[i] != 0)
					ptr_to_matrice->tab[i] += 48;
				if (ptr_to_matrice->tab[i] == 1)
					axe_x += create_object(mlx, mlx_win, "assets/Tree.xpm", axe_x, axe_y);
				else if (ptr_to_matrice->tab[i] == 0)
					axe_x += create_object(mlx, mlx_win, "assets/Grass1.xpm", axe_x, axe_y);
				else if (ptr_to_matrice->tab[i] == 'C')
					axe_x += create_object(mlx, mlx_win, "assets/Tree.xpm", axe_x, axe_y);
				else if (ptr_to_matrice->tab[i] == 'P')
					axe_x += create_object(mlx, mlx_win, "assets/Tree.xpm", axe_x, axe_y);
				else if (ptr_to_matrice->tab[i] == 'E')
					axe_x += create_object(mlx, mlx_win, "assets/Tree.xpm", axe_x, axe_y);
			}
			i++;
		}
		axe_y++;
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
	void	*grass;
	int	img_w;
	int	img_h;

	mlx = mlx_init();	
	grass = mlx_xpm_file_to_image(mlx, "assets/Grass1.xpm", &img_w, &img_h);
	if (!grass)
		return ;
	mlx_win = mlx_new_window(mlx, window_size->width * img_w, window_size->height
			* img_h, "SO_LONG");
	create_map(matrice, window_size, mlx, mlx_win);
	mlx_loop(mlx);
}
