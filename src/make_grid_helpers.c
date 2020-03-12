/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:36:27 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/12 11:16:44 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				grid_helper_2(t_loopers *loop, t_mlx_struct *d_ptr,
double ***arr, double nr)
{
	int				i;
	int				j;
	int				k;
	int				scale;

	i = loop->i;
	j = loop->j;
	k = loop->k;
	scale = d_ptr->grid_size;
	if (!(arr[i][j] = (double*)malloc(sizeof(double) * 3)))
		handle_error("ERROR: malloc, make_grid");
	arr[i][j][0] = (0 - ((d_ptr->columns - 1) * scale / 2) + (j * scale));
	arr[i][j][1] = (0 - ((d_ptr->rows - 1) * scale / 2) + (i * scale));
	arr[i][j][2] = nr * scale;
}

void				grid_helper_3(t_loopers *loop, char *line)
{
	while (line[loop->k] == ' ')
		loop->k++;
	loop->start = loop->k;
	while (line[loop->k] != ' ' && line[loop->k] != '\0')
		loop->k++;
	loop->value = ft_strsub((char const*)line, (unsigned int)loop->start,
	(size_t)loop->k - loop->start);
	loop->number = ft_atoi(loop->value);
	free(loop->value);
}

void				grid_helper_1(t_loopers *loop, t_mlx_struct *data_ptr,
double ***coords_array)
{
	char			*line;

	while ((loop->ret = get_next_line(data_ptr->fd, &line)) == 1)
	{
		if (!(coords_array[loop->i] = (double**)malloc(sizeof(double*) *
		data_ptr->columns)))
			handle_error("ERROR: malloc, make_grid, coords_array");
		loop->j = 0;
		loop->k = 0;
		while (line[loop->k] != '\0')
		{
			grid_helper_3(loop, line);
			grid_helper_2(loop, data_ptr, coords_array, loop->number);
			loop->j++;
		}
		loop->i++;
		ft_strdel(&line);
	}
}
