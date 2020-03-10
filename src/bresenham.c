/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:44:59 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/10 14:15:42 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <math.h>

t_helpers			*make_helpers_struct(void)
{
	t_helpers		*helpers;

	if (!(helpers = (t_helpers *)malloc(sizeof(t_helpers))))
		return (0);
	return (helpers);
}

t_helpers			*get_helpers(t_3d_coords *p0, t_3d_coords *p1)
{
	t_helpers		*helpers;

	if (!(helpers = make_helpers_struct()))
		handle_error("ERROR: bresenham.c, malloc, helpers");
	helpers->dx = abs(p1->x - p0->x);
	helpers->sx = p0->x < p1->x ? 1 : -1;
	helpers->dy = abs(p1->y - p0->y);
	helpers->sy = p0->y < p1->y ? 1 : -1;
	helpers->err = (helpers->dx > helpers->dy ? helpers->dx : -helpers->dy) / 2;
	return (helpers);
}

t_line_data			*make_line_struct(void)
{
	t_line_data		*line_struct;

	if (!(line_struct = (t_line_data*)malloc(sizeof(t_line_data))))
		handle_error("ERROR: bresenham.c, malloc, line_struct");
	return (line_struct);
}

void				draw_line(t_3d_coords *p0, t_3d_coords *p1,
t_mlx_struct *param)
{
	t_line_data		*line_struct;

	line_struct = make_line_struct();
	line_struct->coords = create_coords(p0->x, p0->y, p1->x, p1->y);
	line_struct->helpers = get_helpers(p0, p1);
	while (1)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr,
			line_struct->coords->x0 + WIN_W / 2,
			line_struct->coords->y0 + WIN_H / 2, 0xFFFFF);
		if (line_struct->coords->x0 == line_struct->coords->x1 &&
			line_struct->coords->y0 == line_struct->coords->y1)
			break ;
		line_struct->e2 = line_struct->helpers->err;
		if (line_struct->e2 > -line_struct->helpers->dx)
		{
			line_struct->helpers->err -= line_struct->helpers->dy;
			line_struct->coords->x0 += line_struct->helpers->sx;
		}
		if (line_struct->e2 < line_struct->helpers->dy)
		{
			line_struct->helpers->err += line_struct->helpers->dx;
			line_struct->coords->y0 += line_struct->helpers->sy;
		}
	}
}
