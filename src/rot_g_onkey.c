/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_g_onkey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:42:18 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/23 13:05:54 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				rot_g_onkey(int keycode, t_mlx_struct *coords_ptr)
{
	double		angle;

	if (keycode == 126)
	{
		angle = 0.05;
		rot_grid(coords_ptr->payload, angle, 'x');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload);
	}
	else if (keycode == 125)
	{
		angle = -0.05;
		rot_grid(coords_ptr->payload, angle, 'x');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload);
	}
	else if (keycode == 124)
	{
		angle = 0.05;
		rot_grid(coords_ptr->payload, angle, 'y');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload);;
	}
	else if (keycode == 123)
	{
		angle = -0.05;
		rot_grid(coords_ptr->payload, angle, 'y');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload);
	}
	else if (keycode == 43)
	{
		angle = 0.05;
		rot_grid(coords_ptr->payload, angle, 'z');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload);
	}
	else if (keycode == 47)
	{
		angle = -0.05;
		rot_grid(coords_ptr->payload, angle, 'z');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload);
	}
	
	return (keycode);
}