/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/02/25 16:08:01 by jsuonper         ###   ########.fr       */
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

	if (!(mlx_ptr = mlx_init()))
	{
		ft_putendl("ERROR: mlx_init");
		exit (0);
	}
	if (!(win_ptr = mlx_new_window(mlx_ptr, WIN_W, WIN_H, "test")))
	{
		ft_putendl("ERROR: win_ptr");
		exit (0);
	}

	// MAKE GRID:
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("ERROR: open");
		exit (0);
	}
	size = count_size(fd);
	
	if (close(fd) == -1)
	{
		ft_putendl("ERROR: close");
		exit (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("ERROR: open");
		exit (0);
	}
	coords_arr = make_3d_array(fd, size);
	if (close(fd) == -1)
	{
		ft_putendl("ERROR: close");
		exit (0);
	}

	rot_grid(coords_arr, size, asin(tan(0.523599)), 'x');
	rot_grid(coords_arr, size, 0.785398, 'y');
	draw_grid(mlx_ptr, coords_arr, size);

	// ROTATE ONKEY:
	coords_ptr = create_mlx_struct(mlx_ptr, win_ptr, 0, coords_arr, size);
	mlx_key_hook(win_ptr, rot_g_onkey, coords_ptr);

	
	mlx_loop(mlx_ptr);

	return (ac);
}
