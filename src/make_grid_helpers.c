/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:36:27 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/11 13:38:58 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				grid_helper_2(t_loopers *loop, t_mlx_struct *d_ptr,
double ***arr, double nr)
{
	int				i;
	int				j;
	int				k;
	int				*size;
	int				grid_size;

	i = loop->i;
	j = loop->j;
	k = loop->k;
	size = d_ptr->size;
	grid_size = d_ptr->grid_size;
	if (!(arr[i][j] = (double*)malloc(sizeof(double) * 3)))
		handle_error("ERROR: malloc, make_grid");
	arr[i][j][0] = (0 - ((size[0] - 1) * grid_size / 2) + (j * grid_size));
	arr[i][j][1] = (0 - ((size[1] - 1) * grid_size / 2) + (i * grid_size));
	arr[i][j][2] = nr * grid_size;
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
}

void				grid_helper_1(t_loopers *loop, t_mlx_struct *data_ptr,
double ***coords_array)
{
	char			*line;

	if (!(line = (char*)malloc(sizeof(char) * 1000)))
		handle_error("ERROR: malloc, count_size, line char array");
	while ((loop->ret = get_next_line(data_ptr->fd, &line)) == 1)
	{
		if (!(coords_array[loop->i] = (double**)malloc(sizeof(double*) *
		data_ptr->size[1] + 1)))
			handle_error("ERROR: malloc, make_grid, coords_array");
		loop->j = 0;
		loop->k = 0;
		while (line[loop->k] != '\0')
		{
			grid_helper_3(loop, line);
			grid_helper_2(loop, data_ptr, coords_array, loop->number);
			loop->j++;
		}
		coords_array[loop->i][loop->j] = NULL;
		loop->i++;
		ft_strclr(line);
	}
	free(line);
	coords_array[loop->i] = NULL;
}
