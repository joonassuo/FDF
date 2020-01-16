/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/16 14:02:31 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

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

int				rotate_on_key(int keycode, t_mlx_struct *test) {
	double		angle;

	angle = 0.05;
	if (keycode == 126)
	{
		rotate_cube_x(test->payload, angle);
		rotate_cube_y(test->payload, angle);
		mlx_clear_window(test->mlx_ptr, test->win_ptr);
		draw_cube(test->payload, test->mlx_ptr);
	}
	
	return (keycode);
}

int					main(void)
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_coords		*coords_ptr;
	t_3d_coords		*cube_center;
	t_cube_coords	*cube_coords;
	t_mlx_struct	*struct_ptr;
	t_mlx_struct	*test;
	int				mouse_clicked;
	double			angle;

	mouse_clicked = 0;
	angle = 0.05;

	// initialize mlx window
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");

	// draw line on mouse click
	coords_ptr = create_coords(0, 0, 0, 0);
	struct_ptr = create_mlx_struct(mlx_ptr, win_ptr, coords_ptr, &mouse_clicked);
	mlx_mouse_hook(win_ptr, mouse_draw_line, struct_ptr);

	// draw cube
	cube_center = create_3d_coords(250, 250, 250);
	cube_coords = create_cube_coords(cube_center);
	draw_cube(cube_coords, mlx_ptr);

	// rotate on keypress
	test = create_mlx_struct(mlx_ptr, win_ptr, 0, cube_coords);
	mlx_key_hook(win_ptr, rotate_on_key, test);
	
	mlx_loop(mlx_ptr);
	return (0);
}
