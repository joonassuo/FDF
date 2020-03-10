/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:54:42 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/10 12:55:30 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

t_mlx_struct		*create_mlx_struct(void *mlx_ptr, void *win_ptr,
double ***coords, int *size)
{
	t_mlx_struct	*ret;

	if (!(ret = (t_mlx_struct*)malloc(sizeof(t_mlx_struct))))
		return (0);
	ret->mlx_ptr = mlx_ptr;
	ret->win_ptr = win_ptr;
	ret->coords = coords;
	ret->size = size;
	return (ret);
}
