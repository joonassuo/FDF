/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:43:36 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/20 16:53:13 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int                 *count_size(int fd)
{
    char            *line;
    char            **array;
    int             *res;
    int             rows;
    int             columns;
    int             ret;

    res = (int*)malloc(sizeof(int) * 2);
    rows = 0;
    while ((ret = get_next_line(fd, &line)))
    {
        columns = 0;
        array = ft_strsplit(line, ' ');
        while (array[columns])
            columns++;
        rows++;
    }
    res[0] = rows;
    res[1] = columns;
    return ((int*)res);
}

void                make_3d_array(int fd, int *size)
{
    int             ***coords_array;
    int             i;
    int             j;

    coords_array = (int***)malloc(sizeof(int**) * size[0] + 1);
    i = 0;
    while (i < size[0])
    {
        j = 0;
        coords_array[i] = (int**)malloc(sizeof(int*) * size[1] + 1);
        while (j < size[1])
        {
            coords_array[i][j] = (int*)malloc(sizeof(int) * 3 + 1);
            coords_array[i][j][0] = j;
            coords_array[i][j][1] = i;
            coords_array[i][j][2] = fd;
            coords_array[i][j][3] = '\0';
            j++;
        }
        coords_array[i][j] = NULL;
        i++;
    }
    coords_array[i] = NULL;

    i = 0;
    while (coords_array[i])
    {
        j = 0;
        while (coords_array[i][j])
        {
            printf("x: %d y: %d z: %d\n", coords_array[i][j][0], coords_array[i][j][1], coords_array[i][j][2]);
            j++;
        }
        i++;
    }
}
