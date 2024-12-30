/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:10:07 by marvin            #+#    #+#             */
/*   Updated: 2024/12/30 11:10:29 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../minilibx-linux/mlx.h"
#include "so_long.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// first creat wall function
int	create_wall(t_data img, int i)
{
	int	j;
	int	k;

	j = 0;
	k = i;
	while (i < k + 30)
	{
		j = 0;
		while (j < 30)
		{
			my_mlx_pixel_put(&img, i, j, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
	return (i);
}
int	create_floor(t_data img, int i)
{
	int	j;
	int	k;

	j = 0;
	k = i;
	while (i < k + 30)
	{
		j = 0;
		while (j < 30)
		{
			my_mlx_pixel_put(&img, i, j, 0x0000FFFF);
			j++;
		}
		i++;
	}
	return (i);
}

void	window_handling(t_size *window_size)
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		axe_x;
	t_data	img;

	i = 0;
	axe_x = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, window_size->width * 30, window_size->height
			* 30, "Hello world!");
	img.img = mlx_new_image(mlx, window_size->width * 30, window_size->height
			* 30);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (i < window_size->width)
	{
		axe_x = create_wall(img, axe_x);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
