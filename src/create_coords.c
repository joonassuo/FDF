/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:24:47 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/16 12:32:54 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

t_cube_coords       *create_cube_coords(t_3d_coords *top_left)
{
    t_cube_coords   *ret;
    if (!(ret = (t_cube_coords*)malloc(sizeof(t_cube_coords))))
        return (0);
    ret->c1 = create_3d_coords(top_left->x, top_left->y, top_left->z);
    ret->c2 = create_3d_coords(top_left->x + GRID_SZ, top_left->y, top_left->z);
    ret->c3 = create_3d_coords(top_left->x + GRID_SZ, top_left->y + GRID_SZ, top_left->z);
    ret->c4 = create_3d_coords(top_left->x, top_left->y + GRID_SZ, top_left->z);
    ret->c5 = create_3d_coords(top_left->x, top_left->y, top_left->z + GRID_SZ);
    ret->c6 = create_3d_coords(top_left->x + GRID_SZ, top_left->y, top_left->z + GRID_SZ);
    ret->c7 = create_3d_coords(top_left->x + GRID_SZ, top_left->y + GRID_SZ, top_left->z + GRID_SZ);
    ret->c8 = create_3d_coords(top_left->x, top_left->y + GRID_SZ, top_left->z + GRID_SZ);
    return (ret);
}

t_coords            *create_coords(int x0, int y0, int x1, int y1)
{
    t_coords        *ret;

    if (!(ret = (t_coords*)malloc(sizeof(t_coords))))
        return (0);
    ret->x0 = x0;
    ret->x1 = x1;
    ret->y0 = y0;
    ret->y1 = y1;
    return (ret);
}

t_3d_coords         *create_3d_coords(int x, int y, int z)
{
    t_3d_coords     *ret;

    if (!(ret = (t_3d_coords*)malloc(sizeof(t_3d_coords))))
        return (0);
    ret->x = x;
    ret->y = y;
    ret->z = z;
    return (ret);
}