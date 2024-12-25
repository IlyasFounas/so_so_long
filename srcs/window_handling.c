/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:10:07 by marvin            #+#    #+#             */
/*   Updated: 2024/12/24 12:29:25 by marvin           ###   ########.fr       */
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

// primitiv creat wall function
void	create_wall(t_data img)
{	
    int		i;
	int		j;
    
    i = 0;
	j = 0;
	while (i < 30)
	{
		j = 0;
		while (j < 30)
		{
			my_mlx_pixel_put(&img, i, j, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
}

void	window_handling(void)
{
	void	*mlx;
	void	*mlx_win;

	t_data	img;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 300, "Hello world!");
	img.img = mlx_new_image(mlx, 600, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
    create_wall(img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
