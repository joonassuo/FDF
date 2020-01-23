/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/23 12:22:00 by jsuonper         ###   ########.fr       */
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
	double			*size;
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
	size = count_size(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	coords_arr = make_3d_array(fd, size);
//	rot_grid(coords_arr, asin(tan(30)), 'x');
//	rot_grid(coords_arr, 45, 'y');
	draw_grid(mlx_ptr, coords_arr);

	// ROTATE ONKEY:
	coords_ptr = create_mlx_struct(mlx_ptr, win_ptr, 0, coords_arr);
	mlx_key_hook(win_ptr, rot_g_onkey, coords_ptr);
	mlx_loop(mlx_ptr);

	return (ac);
}
