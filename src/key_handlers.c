/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:22:33 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/12 17:03:17 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int				key_handlers(int keycode, t_mlx_struct *data_ptr)
{
	double		angle;

	printf("%d\n", keycode);
	if (keycode == 126 || keycode == 125)
	{
		angle = (keycode == 126) ? 0.05 : -0.05;
		rot_grid(data_ptr, angle, 'x');
	}
	else if (keycode == 124 || keycode == 123)
	{
		angle = (keycode == 124) ? 0.05 : -0.05;
		rot_grid(data_ptr, angle, 'y');
	}
	else if (keycode == 43 || keycode == 47)
	{
		angle = (keycode == 43) ? 0.05 : -0.05;
		rot_grid(data_ptr, angle, 'z');
	}
	else if (keycode == 53)
		exit(0);
	mlx_clear_window(data_ptr->mlx_ptr, data_ptr->win_ptr);
	draw_grid(data_ptr);
	return (keycode);
}

int				mouse_handlers(int button, int x, int y, t_mlx_struct *data_ptr)
{
	x = 0;
	y = 0;
	if (button == 4)
		data_ptr->grid_size += 2;
	else if (button == 5)
		data_ptr->grid_size -= 2;
	printf("%d\n", button);
	mlx_clear_window(data_ptr->mlx_ptr, data_ptr->win_ptr);
	draw_grid(data_ptr);
	return (button);
}
