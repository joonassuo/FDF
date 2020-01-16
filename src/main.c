/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/16 12:20:38 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					mouse_draw_line(int button, int x, int y, t_mlx_struct *param)
{
	if (!*(int*)param->payload)
	{
		*(int*)param->payload = 1;
		param->coords->x0 = x;
		param->coords->y0 = y;
		return (0);
	}
	else
	{
		*(int*)param->payload = 0;
		draw_line(param->coords->x0, param->coords->y0, x, y, param);
	}
	return (button);
}

int					main(void)
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_coords		*coords_ptr;
	t_3d_coords		*cube_origin;
	t_cube_coords	*cube_coords;
	t_mlx_struct	*struct_ptr;
	int				mouse_clicked;

	mouse_clicked = 0;

	// initialize mlx window
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");

	// draw line on mouse click
	coords_ptr = create_coords(0, 0, 0, 0);
	struct_ptr = create_mlx_struct(mlx_ptr, win_ptr, coords_ptr, &mouse_clicked);
	mlx_mouse_hook(win_ptr, mouse_draw_line, struct_ptr);

	// draw cube test
	cube_origin = create_3d_coords(100, 100, 0);
	cube_coords = create_cube_coords(cube_origin);
	draw_cube(cube_coords, mlx_ptr);
	
	mlx_loop(mlx_ptr);
	return (0);
}
