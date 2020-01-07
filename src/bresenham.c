/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:44:59 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/07 11:01:27 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void        draw_line(int x0, int y0, int x1, int y1, t_mlx_struct *param)
{
    int     dx;
    int     dy;
    int     p;
    int     x;
    int     y;
 
	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	p = 2 * dy - dx; 
	while(x < x1)
	{
		if(p >= 0)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}
