/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:44:59 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/07 18:30:13 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <math.h>

t_helpers *make_helpers_struct(dx, sx, dy, sy, err)
{
	t_helpers *helpers;

	if (!(helpers = (t_helpers *)malloc(sizeof(t_helpers))))
		return (0);
	helpers->dx = dx;
	helpers->sx = sx;
	helpers->dy = dy;
	helpers->sy = sy;
	helpers->err = err;
	return (helpers);
}

t_helpers *get_helpers(t_3d_coords *p0, t_3d_coords *p1)
{
	t_helpers *helpers;
	int dx;
	int sx;
	int dy;
	int sy;
	int err;

	dx = abs(p1->x - p0->x);
	sx = p0->x < p1->x ? 1 : -1;
	dy = abs(p1->y - p0->y);
	sy = p0->y < p1->y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	helpers = make_helpers_struct(dx, sx, dy, sy, err);
	return (helpers);
}

void draw_line(t_3d_coords *p0, t_3d_coords *p1, t_mlx_struct *param)
{
	double padding_w;
	double padding_h;
	int e2;
	t_helpers *helpers;
	int x0;
	int x1;
	int y0;
	int y1;

	x0 = p0->x;
	x1 = p1->x;
	y0 = p0->y;
	y1 = p1->y;
	padding_h = WIN_H / 2;
	padding_w = WIN_W / 2;
	helpers = get_helpers(p0, p1);

	while (1)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x0 + padding_w, y0 + padding_h, 0xFFFFF);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = helpers->err;
		if (e2 > -helpers->dx)
		{
			helpers->err -= helpers->dy;
			x0 += helpers->sx;
		}
		if (e2 < helpers->dy)
		{
			helpers->err += helpers->dx;
			y0 += helpers->sy;
		}
	}
}
