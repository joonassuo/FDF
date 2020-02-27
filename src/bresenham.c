/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:44:59 by jsuonper          #+#    #+#             */
/*   Updated: 2020/02/27 19:00:45 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <math.h>

t_rgb		*create_rgb_struct(int r, int g, int b)
{
	t_rgb	*rgb;

	if (!(rgb = (t_rgb*)malloc(sizeof(t_rgb))))
		return (0);
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return (rgb);
}

t_rgb		*hex_to_rgb(int hex)
{
	t_rgb	*rgb;
	int		r;
	int		g;
	int		b;

	r = ((hex >> 16) & 0xFF);
	g = ((hex >> 8) & 0xFF);
	b = (hex & 0xFF);
	rgb = create_rgb_struct(r, g, b);
	return (rgb);
}

void        	draw_line(t_3d_coords *p0, t_3d_coords *p1, t_mlx_struct *param)
{
	double		padding_w;
    double		padding_h;
	int dx = abs(p1->x - p0->x);
	int sx = p0->x < p1->x ? 1 : -1;
	int dy = abs(p1->y - p0->y);
	int sy = p0->y < p1->y ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
    padding_h = WIN_H / 2;
    padding_w = WIN_W / 2;
	int e2;

	while(1)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, p0->x + padding_w, p0->y + padding_h, 0xFFFFF);
		if (p0->x == p1->x && p0->y == p1->y)
			break;
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			p0->x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			p0->y += sy;
		}
	}
}
