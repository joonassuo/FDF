/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/10 13:35:58 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>
#include <math.h>

int					main(int ac, char **av)
{
	t_mlx_struct	*data_ptr;

	if (!(data_ptr = create_mlx_struct()))
		handle_error("ERROR: main.c, malloc, data_ptr");
	if (!(data_ptr->mlx_ptr = mlx_init()))
		handle_error("ERROR: mlx_init");
	if (!(data_ptr->win_ptr = mlx_new_window(data_ptr->mlx_ptr,
	WIN_W, WIN_H, "test")))
		handle_error("ERROR: win_ptr");
	if ((data_ptr->fd = open(av[1], O_RDONLY)) == -1)
		handle_error("ERROR: open");
	data_ptr->size = count_size(data_ptr->fd);
	if (close(data_ptr->fd) == -1)
		handle_error("ERROR: close");
	if ((data_ptr->fd = open(av[1], O_RDONLY)) == -1)
		handle_error("ERROR: open");
	data_ptr->grid_size = 20;
	data_ptr->coords_arr = make_grid(data_ptr);
	if (close(data_ptr->fd) == -1)
		handle_error("ERROR: close");
	rot_grid(data_ptr->coords_arr, data_ptr->size, asin(tan(0.523599)), 'x');
	rot_grid(data_ptr->coords_arr, data_ptr->size, 0.785398, 'y');
	draw_grid(data_ptr);
	mlx_key_hook(data_ptr->win_ptr, key_handlers, data_ptr);
	mlx_loop(data_ptr->mlx_ptr);
	return (ac);
}
