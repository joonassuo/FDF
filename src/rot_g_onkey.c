/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_g_onkey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:42:18 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/07 17:50:23 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				rot_g_onkey(int keycode, t_mlx_struct *coords_ptr)
{
	double		angle;

	if (keycode == 126 || keycode == 125)
	{
		angle = (keycode == 126) ? 0.05 : -0.05;
		rot_grid(coords_ptr->payload, coords_ptr->size, angle, 'x');
	}
	else if (keycode == 124 || keycode == 123)
	{
		angle = (keycode == 124) ? 0.05 : -0.05;
		rot_grid(coords_ptr->payload, coords_ptr->size, angle, 'y');
	}
	else if (keycode == 43 || keycode == 47)
	{
		angle = (keycode == 43) ? 0.05 : -0.05;
		rot_grid(coords_ptr->payload, coords_ptr->size, angle, 'z');
	}
	else if (keycode == 53)
		exit(0);
	mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
	draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload, coords_ptr->size);
	return (keycode);
}
