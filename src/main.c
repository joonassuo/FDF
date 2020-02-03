/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/02/03 16:30:32 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

int					main(int ac, char **av)
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				*size;
	double			***coords_arr;
	int				fd;
	double			angle;
	t_mlx_struct	*coords_ptr;

	angle = 0.05;

	// INITIALIZE MLX:
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_W, WIN_H, "test");
	

	// MAKE GRID:
	fd = open(av[1], O_RDONLY);
	printf("fd: %d\n", fd);
	printf("open\n");
	size = count_size(fd);
	printf("size\n");
	close(fd);
	printf("close\n");
	fd = open(av[1], O_RDONLY);
	printf("open\n");
	coords_arr = make_3d_array(fd, size);
	printf("coords arr\n");
	if (close(fd) == -1)
	{
		printf("close error");
	} else {
		printf("close successful\n");
	}
	
	rot_grid(coords_arr, asin(tan(0.523599)), 'x');
	rot_grid(coords_arr, 0.785398, 'y');
	printf("rot_grid");
	draw_grid(mlx_ptr, coords_arr);
	printf("draw grid\n");

	// ROTATE ONKEY:
	coords_ptr = create_mlx_struct(mlx_ptr, win_ptr, 0, coords_arr);
	mlx_key_hook(win_ptr, rot_g_onkey, coords_ptr);

	
	mlx_loop(mlx_ptr);

	return (ac);
}
