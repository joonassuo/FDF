/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:43:36 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/11 13:25:00 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int					*count_size(int fd)
{
	char			*line;
	int				*res;
	int				rows;
	int				columns;
	int				ret;
	int				i;
	int				first;

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

t_loopers			*create_looopers(void)
{
	t_loopers		*loop;

	if (!(loop = (t_loopers*)malloc(sizeof(t_loopers))))
		handle_error("ERROR: malloc, t_loopers");
	loop->i = 0;
	loop->j = 0;
	loop->k = 0;
	return (loop);
}

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

void				grid_helper_1(t_loopers *loop, char *line)
{
	int				i;
	int				j;
	int				k;

	i = loop->i;
	j = loop->j;
	k = loop->k;
	while (line[k] == ' ')
		k++;
	loop->start = k;
	while (line[k] != ' ' && line[k] != '\0')
		k++;
	loop->value = ft_strsub((char const*)line, (unsigned int)loop->start,
		(size_t)k - loop->start);
	loop->number = ft_atoi(loop->value);
}

double				***make_grid(t_mlx_struct *data_ptr)
{
	char			*line;
	double			***coords_array;
	t_loopers		*loop;

	if (!(line = (char*)malloc(sizeof(char) * 1000)))
		handle_error("ERROR: malloc, count_size, line char array");
	if (!(coords_array = (double***)malloc(sizeof(double**) *
	data_ptr->size[0] + 1)))
		handle_error("ERROR: malloc, make_grid, coords_array");
	loop = create_looopers();
	while ((loop->ret = get_next_line(data_ptr->fd, &line)) == 1)
	{
		if (!(coords_array[loop->i] = (double**)malloc(sizeof(double*) *
		data_ptr->size[1] + 1)))
			handle_error("ERROR: malloc, make_grid, coords_array");
		loop->j = 0;
		loop->k = 0;
		while (line[loop->k] != '\0')
		{
			while (line[loop->k] == ' ')
				loop->k++;
			loop->start = loop->k;
			while (line[loop->k] != ' ' && line[loop->k] != '\0')
				loop->k++;
			loop->value = ft_strsub((char const*)line, (unsigned int)loop->start,
			(size_t)loop->k - loop->start);
			loop->number = ft_atoi(loop->value);
			grid_helper_2(loop, data_ptr, coords_array, loop->number);
			loop->j++;
		}
		coords_array[loop->i][loop->j] = NULL;
		loop->i++;
		ft_strclr(line);
	}
	free (line);
	coords_array[loop->i] = NULL;
	return (coords_array);
}
