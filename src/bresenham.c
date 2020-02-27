/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:44:59 by jsuonper          #+#    #+#             */
/*   Updated: 2020/02/27 18:02:39 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

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

void        draw_line(int x0, int y0, int x1, int y1, t_mlx_struct *param)
{
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while(1)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x0, y0, 0xFFFFF);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}
