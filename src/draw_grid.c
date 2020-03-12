/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:29:51 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/12 14:26:25 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				draw_square(t_mlx_struct *data_ptr, int x, int y)
{
	t_3d_coords		*p1;
	t_3d_coords		*p2;
	t_3d_coords		*p3;

	p1 = create_3d_coords(data_ptr->coords_arr[y][x]);
	if (!(x == data_ptr->columns - 1))
	{
		p2 = create_3d_coords(data_ptr->coords_arr[y][x + 1]);
		draw_line(p1, p2, data_ptr->mlx_ptr);
		free(p2);
	}
	if (!(y == data_ptr->rows - 1))
	{
		p3 = create_3d_coords(data_ptr->coords_arr[y + 1][x]);
		draw_line(p1, p3, data_ptr->mlx_ptr);
		free(p3);
	}
	free(p1);
}

void				draw_grid(t_mlx_struct *data_ptr)
{
	int				i;
	int				j;

	i = 0;
	while (i < data_ptr->rows)
	{
		j = 0;
		while (j < data_ptr->columns)
		{
			draw_square(data_ptr, j, i);
			j++;
		}
		i++;
	}
}
