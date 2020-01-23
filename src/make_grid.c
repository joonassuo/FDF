/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:43:36 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/23 11:59:32 by jsuonper         ###   ########.fr       */
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

double              ***make_3d_array(int fd, int *size)
{
    char            *line;
    char            **num_array;
    double          ***coords_array;
    int             i;
    int             j;
    int             ret;


    coords_array = (double***)malloc(sizeof(double**) * size[0] + 1);
    i = 0;
    while (i < size[0])
    {
        ret = get_next_line(fd, &line);
        num_array = ft_strsplit(line, ' ');
        j = 0;
        coords_array[i] = (double**)malloc(sizeof(double*) * size[1] + 1);
        while (j < size[1])
        {
            coords_array[i][j] = (double*)malloc(sizeof(double) * 3 + 1);
            coords_array[i][j][0] = (WIN_W / 2) - (size[0] / 2) + (j * GRID_SZ);
            coords_array[i][j][1] = (WIN_H / 2) - (size[1] / 2) + (i * GRID_SZ);
            coords_array[i][j][2] = ft_atoi(num_array[j]) * GRID_SZ;
            coords_array[i][j][3] = '\0';
            j++;
        }
        coords_array[i][j] = NULL;
        j = 0;
        while (num_array[j])
        {
            free(num_array[j]);
            j++;
        }
        free(num_array);
        i++;
    }
    coords_array[i] = NULL;
    return (coords_array);
}

void            draw_square(t_mlx_struct *mlx_ptr, double ***coords_arr, int x, int y)
{
    draw_line(
        coords_arr[y][x][0],
        coords_arr[y][x][1],
        coords_arr[y][x + 1][0],
        coords_arr[y][x + 1][1],
        mlx_ptr
    );
    draw_line(
        coords_arr[y][x][0],
        coords_arr[y][x][1],
        coords_arr[y + 1][x][0],
        coords_arr[y + 1][x][1],
        mlx_ptr
    );
    draw_line(
        coords_arr[y][x + 1][0],
        coords_arr[y][x + 1][1],
        coords_arr[y + 1][x + 1][0],
        coords_arr[y + 1][x + 1][1],
        mlx_ptr
    );
    draw_line(
        coords_arr[y + 1][x + 1][0],
        coords_arr[y + 1][x + 1][1],
        coords_arr[y + 1][x][0],
        coords_arr[y + 1][x][1],
        mlx_ptr
    );
}

void            draw_grid(t_mlx_struct *mlx_ptr, double ***coords_arr)
{
    int         i;
    int         j;

    i = 0;
    while (coords_arr[i + 1])
    {
        j = 0;
        while (coords_arr[i][j + 1])
        {
            draw_square(mlx_ptr, coords_arr, j, i);
            j++;
        }
        i++;
    }
}
