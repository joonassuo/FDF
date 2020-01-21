/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:32:38 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/21 14:56:38 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
#include <stdio.h>

void        rot_coords(int *coords, double angle, char axel)
{
    int     temp;
    int     i;
    int     j;

    if (axel == 'z')
    {
        i = 0;
        j = 1;
    } 
    else if (axel == 'x')
    {
        i = 1;
        j = 2;
    }
    else
    {
        i = 0;
        j = 2;
    }
    temp = coords[i];
    coords[i] = coords[i] * cos(angle) - coords[j] * sin(angle);
    coords[j] = coords[j] * cos(angle) - temp * sin(angle);
}

void        rot_grid(int ***coords_arr, double angle, char axel)
{
    int     i;
    int     j;

    i = 0;
    while (coords_arr[i])
    {
        j = 0;
        while (coords_arr[i][j])
        {
            rot_coords(coords_arr[i][j], angle, axel);
            j++;
        }
        i++;
    }
}