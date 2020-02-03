/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_3d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:21:21 by jsuonper          #+#    #+#             */
/*   Updated: 2020/02/03 17:23:26 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void            free_3d_array(t_mlx_struct *ptr)
{
    double      ****array;
    int         i;
    int         j;
    int         k;

    array = ptr->payload;
    i = 0;
    while (array[i])
    {
        j = 0;
        while (array[i][j])
        {
            k = 0;
            while (k < 4)
            {
                free(array[i][j][0]);
                free(array[i][j][1]);
                free(array[i][j][2]);
                free(array[i][j][3]);
                k++;
            }
            free(array[i][j]);
            j++;
        }
        free(array[i]);
        i++;
    }
    free (array);
    mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
}