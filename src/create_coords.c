/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:24:47 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/07 18:32:18 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

t_coords        *create_coords(int x0, int y0, int x1, int y1)
{
    t_coords *ret;

    if (!(ret = (t_coords *)malloc(sizeof(t_coords))))
        return (0);
    ret->x0 = x0;
    ret->x1 = x1;
    ret->y0 = y0;
    ret->y1 = y1;
    return (ret);
}

t_3d_coords *create_3d_coords(double *coords)
{
    t_3d_coords *ret;

    if (!(ret = (t_3d_coords *)malloc(sizeof(t_3d_coords))))
        return (0);
    ret->x = coords[0];
    ret->y = coords[1];
    ret->z = coords[2];
    return (ret);
}
