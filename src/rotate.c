/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:03:16 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/21 13:00:54 by jsuonper         ###   ########.fr       */
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

void        rotate_cube_z(t_cube_coords *cube_coords, double angle)
{
    rotate_z(cube_coords->c1, angle);
    rotate_z(cube_coords->c2, angle);
    rotate_z(cube_coords->c3, angle);
    rotate_z(cube_coords->c4, angle);
    rotate_z(cube_coords->c5, angle);
    rotate_z(cube_coords->c6, angle);
    rotate_z(cube_coords->c7, angle);
    rotate_z(cube_coords->c8, angle);
}

void        rotate_cube_x(t_cube_coords *cube_coords, double angle)
{
    rotate_x(cube_coords->c1, angle);
    rotate_x(cube_coords->c2, angle);
    rotate_x(cube_coords->c3, angle);
    rotate_x(cube_coords->c4, angle);
    rotate_x(cube_coords->c5, angle);
    rotate_x(cube_coords->c6, angle);
    rotate_x(cube_coords->c7, angle);
    rotate_x(cube_coords->c8, angle);
}

void        rotate_cube_y(t_cube_coords *cube_coords, double angle)
{
    rotate_y(cube_coords->c1, angle);
    rotate_y(cube_coords->c2, angle);
    rotate_y(cube_coords->c3, angle);
    rotate_y(cube_coords->c4, angle);
    rotate_y(cube_coords->c5, angle);
    rotate_y(cube_coords->c6, angle);
    rotate_y(cube_coords->c7, angle);
    rotate_y(cube_coords->c8, angle);
}