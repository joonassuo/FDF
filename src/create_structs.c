/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:50:35 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/11 13:57:09 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <math.h>

t_helpers			*create_helpers_struct(void)
{
	t_helpers		*helpers;

	if (!(helpers = (t_helpers *)malloc(sizeof(t_helpers))))
		return (0);
	return (helpers);
}

t_line_data			*create_line_struct(void)
{
	t_line_data		*line_struct;

	if (!(line_struct = (t_line_data*)malloc(sizeof(t_line_data))))
		handle_error("ERROR: bresenham.c, malloc, line_struct");
	return (line_struct);
}

t_mlx_struct		*create_mlx_struct(void)
{
	t_mlx_struct	*ret;

	if (!(ret = (t_mlx_struct*)malloc(sizeof(t_mlx_struct))))
		return (0);
	ret->total_x = asin(tan(0.523599));
	ret->total_y = 0.785398;
	ret->total_z = 0;
	return (ret);
}

t_size_helpers		*create_size_helpers(void)
{
	t_size_helpers	*helper;

	if (!(helper = (t_size_helpers*)malloc(sizeof(t_size_helpers))))
		handle_error("ERROR: malloc, size_helper");
	helper->rows = 0;
	helper->columns = 0;
	helper->i = 0;
	helper->first = 1;
	return (helper);
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
