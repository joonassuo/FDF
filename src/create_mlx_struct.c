/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mlx_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:54:42 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/10 17:37:34 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <math.h>

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
