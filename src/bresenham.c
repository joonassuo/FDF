/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:44:59 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/12 11:21:22 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <math.h>

t_helpers			*get_helpers(t_3d_coords *p0, t_3d_coords *p1)
{
	t_helpers		*helpers;

	if (!(helpers = create_helpers_struct()))
		handle_error("ERROR: bresenham.c, malloc, helpers");
	helpers->dx = abs(p1->x - p0->x);
	helpers->sx = p0->x < p1->x ? 1 : -1;
	helpers->dy = abs(p1->y - p0->y);
	helpers->sy = p0->y < p1->y ? 1 : -1;
	helpers->err = (helpers->dx > helpers->dy ? helpers->dx : -helpers->dy) / 2;
	return (helpers);
}

void				free_line_struct(t_line_data *l)
{
	free(l->coords);
	free(l->helpers);
	free(l);
}

void				draw_line(t_3d_coords *p0, t_3d_coords *p1,
t_mlx_struct *param)
{
	t_line_data		*l;

	l = create_line_struct();
	l->coords = create_coords(p0->x, p0->y, p1->x, p1->y);
	l->helpers = get_helpers(p0, p1);
	while (1)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr,
			l->coords->x0 + WIN_W / 2, l->coords->y0 + WIN_H / 2, 0xFFFFF);
		if (l->coords->x0 == l->coords->x1 && l->coords->y0 == l->coords->y1)
			break ;
		l->e2 = l->helpers->err;
		if (l->e2 > -l->helpers->dx)
		{
			l->helpers->err -= l->helpers->dy;
			l->coords->x0 += l->helpers->sx;
		}
		if (l->e2 < l->helpers->dy)
		{
			l->helpers->err += l->helpers->dx;
			l->coords->y0 += l->helpers->sy;
		}
	}
	free_line_struct(l);
}
