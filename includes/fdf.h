/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:48:52 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/16 12:33:15 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define GRID_SZ 200
# include "../miniLibX/mlx.h"
# include "../libft/libft.h"

typedef struct		s_coords
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_coords;

typedef struct		s_3d_coords
{
	int				x;
	int				y;
	int				z;
}					t_3d_coords;

typedef struct		s_cube_coords
{
	t_3d_coords		*c1;
	t_3d_coords		*c2;
	t_3d_coords		*c3;
	t_3d_coords		*c4;
	t_3d_coords		*c5;
	t_3d_coords		*c6;
	t_3d_coords		*c7;
	t_3d_coords		*c8;
}					t_cube_coords;

typedef struct		s_mlx_struct
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_coords		*coords;
	void			*payload;
}					t_mlx_struct;

t_3d_coords			*create_3d_coords(int x, int y, int z);
t_coords			*create_coords(int x0, int y0, int x1, int y1);
t_cube_coords       *create_cube_coords(t_3d_coords *top_left);
t_mlx_struct		*create_mlx_struct(void *mlx_ptr, void *win_ptr, t_coords *coords, void *payload);
void        		draw_cube(t_cube_coords *cube_coords, t_mlx_struct *mlx);
void				draw_line(int x0, int y0, int x1, int y1, t_mlx_struct *param);
void            	make_square(t_mlx_struct *param);

#endif
