/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:43:36 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/10 18:17:02 by jsuonper         ###   ########.fr       */
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
        handle_error("ERROR: malloc, count_size, int array");
    if (!(line = (char*)malloc(sizeof(char) * 1000)))
        handle_error("ERROR: malloc, count_size, line char array");
    rows = 0;
    columns = 0;
    i = 0;
    first = 1;

    while ((ret = get_next_line(fd, &line)) == 1)
    {
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

double              ***make_grid(t_mlx_struct *data_ptr)
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

    if (!(coords_array = (double***)malloc(sizeof(double**) * data_ptr->size[0] + 1)))
        handle_error("ERROR: malloc, make_grid, coords_array");
    i = 0;
    j = 0;
    while ((ret = get_next_line(data_ptr->fd, &line)) == 1)
    {
        if (!(coords_array[i] = (double**)malloc(sizeof(double*) * data_ptr->size[1] + 1)))
            handle_error("ERROR: malloc, make_grid, coords_array");
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
                handle_error("ERROR: malloc, make_grid, coords_array[i][j]");
            coords_array[i][j][0] = (double)(0 - ((data_ptr->size[0] - 1) * data_ptr->grid_size / 2) + (j * data_ptr->grid_size));
            coords_array[i][j][1] = (double)(0 - ((data_ptr->size[1] - 1) * data_ptr->grid_size / 2) + (i * data_ptr->grid_size));
            coords_array[i][j][2] = (double)number * data_ptr->grid_size;
            j++;
        }
        coords_array[i][j] = NULL;
        i++;
    }
    coords_array[i] = NULL;
    return (coords_array);
}
