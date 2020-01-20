/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:43:36 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/20 14:15:29 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void        make_3d_array(int fd)
{
    char    *line;
    int     ret;

    ret = get_next_line(fd, &line);
    printf("%s\n", line);
}

/*
void        make_grid(t_mlx_struct *mlx_ptr, int **array)
{
    int     i;
    int     j;

    i = 0;
    while (array[i])
    {
        j = 0;
        while (array[i][j])
        {

        }
    }
}
*/