/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_g_onkey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:42:18 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/23 13:44:29 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>


void			change_z(double ***coords_arr, char *param)
{
	int			i;
	int			j;
	int			change;

	i = 0;
	change = (ft_strcmp(param, "increase") == 0) ? Z_CHANGE : -Z_CHANGE;

	while (coords_arr[i])
	{
		j = 0;
		while (coords_arr[i][j])
		{
			coords_arr[i][j][2] += change;
			j++;
		}
		i++;
	}
}

int				rot_g_onkey(int keycode, t_mlx_struct *coords_ptr)
{
	double		angle;

	if (keycode == 0)
	{
		change_z(coords_ptr->payload, "increase");
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload);
	}
	else if (keycode == 1)
	{
		change_z(coords_ptr->payload, "decrease");
		mlx_clear_window(coords_ptr->mlx_ptr, coords_ptr->win_ptr);
		draw_grid(coords_ptr->mlx_ptr, coords_ptr->payload);
	}
	else if (keycode == 126)
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