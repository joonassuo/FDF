/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_g_onkey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:42:18 by jsuonper          #+#    #+#             */
/*   Updated: 2020/02/25 16:56:25 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>


void			zoom_in(void)
{
	printf("lol");
	#undef GRID_SZ
	# define GRID_SZ 20
}

int				rot_g_onkey(int keycode, t_mlx_struct *coords_ptr)
{
	double		angle;

	if (keycode == 0)
	{
		zoom_in();
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload, coords_ptr->size);
	}
	else if (keycode == 1)
	{
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload, coords_ptr->size);
	}
	else if (keycode == 126)
	{
		angle = 0.05;
		rot_grid(coords_ptr->payload, coords_ptr->size, angle, 'x');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload, coords_ptr->size);
	}
	else if (keycode == 125)
	{
		angle = -0.05;
		rot_grid(coords_ptr->payload, coords_ptr->size, angle, 'x');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload, coords_ptr->size);
	}
	else if (keycode == 124)
	{
		angle = 0.05;
		rot_grid(coords_ptr->payload, coords_ptr->size, angle, 'y');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload, coords_ptr->size);
	}
	else if (keycode == 123)
	{
		angle = -0.05;
		rot_grid(coords_ptr->payload, coords_ptr->size, angle, 'y');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload, coords_ptr->size);
	}
	else if (keycode == 43)
	{
		angle = 0.05;
		rot_grid(coords_ptr->payload, coords_ptr->size, angle, 'z');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload, coords_ptr->size);
	}
	else if (keycode == 47)
	{
		angle = -0.05;
		rot_grid(coords_ptr->payload, coords_ptr->size, angle, 'z');
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload, coords_ptr->size);
	}
	else if (keycode == 53)
	{
		free_3d_array(coords_ptr);
	}
	
	return (keycode);
}