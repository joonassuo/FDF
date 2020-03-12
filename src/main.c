/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/12 15:32:45 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

void				close_open(int fd, char *file)
{
	if (close(fd) == -1)
		handle_error("ERROR: close");
	if ((fd = open(file, O_RDONLY)) == -1)
		handle_error("ERROR: open");
}

int					main(int ac, char **av)
{
	t_mlx_struct	*data_ptr;

	data_ptr = create_mlx_struct();
	if (!(data_ptr->mlx_ptr = mlx_init()))
		handle_error("ERROR: mlx_init");
	if (!(data_ptr->win_ptr = mlx_new_window(data_ptr->mlx_ptr,
	WIN_W, WIN_H, "test")))
		handle_error("ERROR: win_ptr");
	if ((data_ptr->fd = open(av[1], O_RDONLY)) == -1)
		handle_error("ERROR: open");
	validate_map(data_ptr->fd);
	close_open(data_ptr->fd, av[1]);
	count_size(data_ptr);
	close_open(data_ptr->fd, av[1]);
	data_ptr->grid_size = 20;
	data_ptr->coords_arr = make_grid(data_ptr);
	close_open(data_ptr->fd, av[1]);
	if (close(data_ptr->fd) == -1)
		handle_error("ERROR: close");
	draw_grid(data_ptr);
	mlx_key_hook(data_ptr->win_ptr, key_handlers, data_ptr);
	mlx_loop(data_ptr->mlx_ptr);
	return (ac);
}
