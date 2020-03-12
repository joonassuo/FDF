/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:44:59 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/12 17:03:38 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <math.h>

void			free_all(t_coords *c, t_helpers *h)
{
	free(h);
	free(c);
}

void			draw_line(t_3d_coords *p0, t_3d_coords *p1,
t_mlx_struct *data_ptr)
{
	t_coords	*c;
	t_helpers	*h;

	c = create_coords(p0->x * data_ptr->grid_size, p0->y * data_ptr->grid_size,
	p1->x * data_ptr->grid_size, p1->y * data_ptr->grid_size);
	h = create_helpers_struct(c);
	while (1)
	{
		mlx_pixel_put(data_ptr->mlx_ptr, data_ptr->win_ptr,
		c->x0 + WIN_W / 2, c->y0 + WIN_H / 2, 0xFFFFF);
		if (c->x0 == c->x1 && c->y0 == c->y1)
			break ;
		h->e2 = h->err;
		if (h->e2 > -h->dx)
		{
			h->err -= h->dy;
			c->x0 += h->sx;
		}
		if (h->e2 < h->dy)
		{
			h->err += h->dx;
			c->y0 += h->sy;
		}
	}
	free_all(c, h);
}
