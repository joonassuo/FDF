/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:32:38 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/12 15:30:02 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
#include <stdio.h>

void		rot_coords(double *coords, double angle, char axel)
{
	double	temp;
	int		i;
	int		j;

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
	coords[j] = coords[j] * cos(angle) + temp * sin(angle);
}

void		rot_grid(t_mlx_struct *data_ptr, double angle, char axel)
{
	int		i;
	int		j;

	i = 0;
	while (i < data_ptr->rows)
	{
		j = 0;
		while (j < data_ptr->columns)
		{
			rot_coords(data_ptr->coords_arr[i][j], angle, axel);
			j++;
		}
		i++;
	}
}
