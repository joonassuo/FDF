/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:43:36 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/11 13:53:39 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void				size_helper(t_size_helpers *helper, char *line)
{
	while ((line[helper->i] >= '0' && line[helper->i] <= '9')
	|| line[helper->i] == '-')
		helper->i++;
	helper->columns++;
	while (line[helper->i] == ' ')
		helper->i++;
}

int					*count_size(int fd)
{
	char			*line;
	int				*res;
	t_size_helpers	*helper;

	if (!(res = (int*)malloc(sizeof(int) * 2)))
		handle_error("ERROR: malloc, count_size, int array");
	if (!(line = (char*)malloc(sizeof(char) * 1000)))
		handle_error("ERROR: malloc, count_size, line char array");
	helper = create_size_helpers();
	while ((helper->ret = get_next_line(fd, &line)) == 1)
	{
		if (helper->first)
		{
			while (line[helper->i])
				size_helper(helper, line);
			helper->first = 0;
		}
		helper->rows++;
		ft_strclr(line);
	}
	res[0] = helper->rows;
	res[1] = helper->columns;
	free(line);
	return (res);
}

double				***make_grid(t_mlx_struct *data_ptr)
{
	double			***coords_array;
	t_loopers		*loop;

	if (!(coords_array = (double***)malloc(sizeof(double**) *
	data_ptr->size[0] + 1)))
		handle_error("ERROR: malloc, make_grid, coords_array");
	loop = create_looopers();
	grid_helper_1(loop, data_ptr, coords_array);
	return (coords_array);
}
