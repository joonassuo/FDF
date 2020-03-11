/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:43:36 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/11 17:34:42 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void				count_size(t_mlx_struct *data_ptr)
{
	char			*line;
	char			**split_arr;
	t_size_helpers	*helper;

	helper = create_size_helpers();
	while ((helper->ret = get_next_line(data_ptr->fd, &line)) == 1)
	{
		if (helper->first)
		{
			split_arr = ft_strsplit(line, ' ');
			while (split_arr[helper->i])
			{
				free(split_arr[helper->i]);
				helper->columns++;
				helper->i++;
			}
			free(split_arr);
			helper->first = 0;
		}
		helper->rows++;
		free(line);
	}
	free(helper);
	data_ptr->rows = helper->rows;
	data_ptr->columns = helper->columns;
}

double				***make_grid(t_mlx_struct *data_ptr)
{
	double			***coords_array;
	t_loopers		*loop;

	if (!(coords_array = (double***)malloc(sizeof(double**) *
	data_ptr->rows + 1)))
		handle_error("ERROR: malloc, make_grid, coords_array");
	loop = create_looopers();
	grid_helper_1(loop, data_ptr, coords_array);
	return (coords_array);
}
