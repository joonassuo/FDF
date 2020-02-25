/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:43:36 by jsuonper          #+#    #+#             */
/*   Updated: 2020/02/25 16:08:00 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int                 *count_size(int fd)
{
    char            *line;
    int             *res;
    int             rows;
    int             columns;
    int             ret;
    int             i;
    int             first;

    if (!(res = (int*)malloc(sizeof(int) * 2)))
    {
        ft_putendl("ERROR: malloc, count_size, int array");
        exit (0);
    }
    if (!(line = (char*)malloc(sizeof(char) * 1000)))
    {
        ft_putendl("ERROR: malloc, count_size, line char array");
        exit (0);
    }
    rows = 0;
    columns = 0;
    i = 0;
    first = 1;


    while ((ret = get_next_line(fd, &line)) == 1)
    {
        printf("%s\n", line);
        if (first)
        {
            while (line[i])
            {
                while ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
                    i++;
                columns++;
                while (line[i] == ' ')
                    i++;
            }
            first = 0;
        }
        rows++;
        ft_strclr(line);
    }    
    
    res[0] = rows;
    res[1] = columns;
    free(line);
    return (res);
}

double              ***make_3d_array(int fd, int *size)
{
    char            *line;
    char            *value;
    double          ***coords_array;
    double          number;
    int             start;
    int             i;
    int             j;
    int             k;
    int             ret;

    if (!(coords_array = (double***)malloc(sizeof(double**) * size[0])))
    {
        ft_putendl("ERROR: malloc, make_3d_array, coords_array");
        exit (0);
    }
    i = 0;
    j = 0;
    while ((ret = get_next_line(fd, &line)) == 1)
    {
        if (!(coords_array[i] = (double**)malloc(sizeof(double*) * size[1])))
        {
            ft_putendl("ERROR: malloc, make_3d_array, coords_array");
            exit (0);
        }
        j = 0;
        k = 0;
        while (line[k] != '\0')
        {
            while (line[k] == ' ')
                k++;
            start = k;
            while (line[k] != ' ' && line[k] != '\0')
                k++;
            value = ft_strsub((char const*)line, (unsigned int)start, (size_t)k - start);
            number = (double)ft_atoi(value);
            if (!(coords_array[i][j] = (double*)malloc(sizeof(double) * 3)))
            {
                ft_putendl("ERROR: malloc, make_3d_array, coords_array[i][j]");
                exit (0);
            }
            coords_array[i][j][0] = (double)(0 - ((size[0] - 1) * GRID_SZ / 2) + (j * GRID_SZ));
            coords_array[i][j][1] = (double)(0 - ((size[1] - 1) * GRID_SZ / 2) + (i * GRID_SZ));
            coords_array[i][j][2] = (double)number * GRID_SZ;
            //coords_array[i][j][3] = '\0';
            j++;
        }
        coords_array[i][j] = NULL;
        i++;
    }
    coords_array[i] = NULL;
    printf("end of make 3d arr\n");
    return (coords_array);
}


/* int                 *count_size(int fd)
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
} */

/* double              ***make_3d_array(int fd, int *size)
{
    printf("%d\n", size[0]);
    printf("%d\n", size[1]);
    char            *line;
    char            **num_array;
    double          ***coords_array;
    int             i;
    int             j;
    int             ret;

    coords_array = (double***)malloc(sizeof(double**) * size[0] + 1);
    line = ft_strnew(LINE_BUFF);
    i = 0;
    while (i < size[0])
    {
        printf("%d\n", i);
        printf("fd: %d\n", fd);
        ret = get_next_line(fd, &line);
        printf("get next line: %d\n", ret);
        printf("%d\n", i);
        num_array = ft_strsplit(line, ' ');
        j = 0;
        coords_array[i] = (double**)malloc(sizeof(double*) * size[1] + 1);
        while (j < size[1])
        {
            coords_array[i][j] = (double*)malloc(sizeof(double) * 3 + 1);
            coords_array[i][j][0] = 0 - ((size[0] - 1) * GRID_SZ / 2) + (j * GRID_SZ);
            coords_array[i][j][1] = 0 - ((size[1] - 1) * GRID_SZ / 2) + (i * GRID_SZ);
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
        printf("%d\n", i);
        i++;
        ft_strclr(line);
    }
    ft_strdel(&line);
    coords_array[i] = NULL;
    return (coords_array);
} */

void            draw_square(t_mlx_struct *mlx_ptr, double ***coords_arr, int x, int y)
{
    double      padding_w;
    double      padding_h;

    padding_h = WIN_H / 2;
    padding_w = WIN_W / 2;
    draw_line(
        coords_arr[y][x][0] + padding_w,
        coords_arr[y][x][1] + padding_h,
        coords_arr[y][x + 1][0] + padding_w,
        coords_arr[y][x + 1][1] + padding_h,
        mlx_ptr
    );
    draw_line(
        coords_arr[y][x][0] + padding_w,
        coords_arr[y][x][1] + padding_h,
        coords_arr[y + 1][x][0] + padding_w,
        coords_arr[y + 1][x][1] + padding_h,
        mlx_ptr
    );
    draw_line(
        coords_arr[y][x + 1][0] + padding_w,
        coords_arr[y][x + 1][1] + padding_h,
        coords_arr[y + 1][x + 1][0] + padding_w,
        coords_arr[y + 1][x + 1][1] + padding_h,
        mlx_ptr
    );
    draw_line(
        coords_arr[y + 1][x + 1][0] + padding_w,
        coords_arr[y + 1][x + 1][1] + padding_h,
        coords_arr[y + 1][x][0] + padding_w,
        coords_arr[y + 1][x][1] + padding_h,
        mlx_ptr
    );
}

void            draw_grid(t_mlx_struct *mlx_ptr, double ***coords_arr, int *size)
{
    int         i;
    int         j;

    i = 0;
    while (i < size[0] - 1)
    {
        j = 0;
        while (j < size[1] - 1)
        {
            draw_square(mlx_ptr, coords_arr, j, i);
            j++;
        }
        i++;
    }
}
