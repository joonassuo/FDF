/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:48:52 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/07 11:38:40 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include "../miniLibX/mlx.h"
# include "../libft/libft.h"

typedef struct		s_coords
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_coords;

typedef struct		s_mlx_struct
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_coords		*coords;
	void			*payload;
}					t_mlx_struct;

t_coords			*create_coords(int x0, int y0, int x1, int y1);
t_mlx_struct		*create_mlx_struct(void *mlx_ptr, void *win_ptr, t_coords *coords, void *payload);
void				draw_line(int x0, int y0, int x1, int y1, t_mlx_struct *param);

#endif
