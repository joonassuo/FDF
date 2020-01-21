/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/21 13:05:50 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <fcntl.h>

int					main(int ac, char **av)
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				*size;
	int				***coords_arr;
	int				fd;
	double			angle;

	angle = 0.05;


	// INITIALIZE MLX:
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	

	// MAKE GRID:
	fd = open(av[1], O_RDONLY);
	size = count_size(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	coords_arr = make_3d_array(fd, size);
		
	draw_grid(mlx_ptr, coords_arr);
	mlx_loop(mlx_ptr);

	return (ac);
}
