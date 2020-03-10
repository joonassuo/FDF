/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:03:16 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/10 12:50:33 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void        rotate_z(t_3d_coords *coords, double angle)
{
    int     temp;

    temp = coords->x;
    coords->x = coords->x * cos(angle) - coords->y * sin(angle);
    coords->y = coords->y * cos(angle) - temp * sin(angle);
}

void        rotate_x(t_3d_coords *coords, double angle)
{
    int     temp;

    temp = coords->y;
    coords->y = coords->y * cos(angle) - coords->z * sin(angle);
    coords->z = coords->z * cos(angle) - temp * sin(angle);
}

void        rotate_y(t_3d_coords *coords, double angle)
{
    int     temp;

    temp = coords->x;
    coords->x = coords->x * cos(angle) - coords->z * sin(angle);
    coords->z = coords->z * cos(angle) - temp * sin(angle);
}
