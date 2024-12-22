/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:43:09 by marvin            #+#    #+#             */
/*   Updated: 2024/12/23 00:46:30 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "so_long.h"
# include "../minilibx-linux/mlx.h"


int	main(void)
{
    int fd;
    char *line;
	// void	*mlx;
    // void    *mlx_win;

	// mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 300, 300, "Hello world!");
	// mlx_loop(mlx);
	void	*img;
	void	*mlx;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
    fd = open("maps/map1.ber", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    printf("%p", img);
    free(line);
}
