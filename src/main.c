/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/10 12:56:23 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

void				hadle_error(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

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
	if (!(mlx_ptr = mlx_init()))
		hadle_error("ERROR: mlx_init");
	if (!(win_ptr = mlx_new_window(mlx_ptr, WIN_W, WIN_H, "test")))
		hadle_error("ERROR: win_ptr");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		hadle_error("ERROR: open");
	size = count_size(fd);
	if (close(fd) == -1)
		hadle_error("ERROR: close");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		hadle_error("ERROR: open");
	coords_arr = make_3d_array(fd, size);
	if (close(fd) == -1)
		hadle_error("ERROR: close");
	rot_grid(coords_arr, size, asin(tan(0.523599)), 'x');
	rot_grid(coords_arr, size, 0.785398, 'y');
	draw_grid(mlx_ptr, coords_arr, size);
	coords_ptr = create_mlx_struct(mlx_ptr, win_ptr, coords_arr, size);
	mlx_key_hook(win_ptr, rot_g_onkey, coords_ptr);
	mlx_loop(mlx_ptr);
	return (ac);
}
