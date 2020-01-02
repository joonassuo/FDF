/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:48:52 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/02 17:03:43 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include "../miniLibX/mlx.h"
# include "../libft/libft.h"

typedef struct		s_mlx_struct
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx_struct;

t_mlx_struct		*create_mlx_struct(void *mlx_ptr, void *win_ptr);

#endif
