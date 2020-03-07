/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:48:52 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/07 18:09:43 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define GRID_SZ 20
# define WIN_H 1500
# define WIN_W 2500
# define Z_CHANGE 10
# define LINE_BUFF 1000
# include "../miniLibX/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct		s_helpers
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
}					t_helpers;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

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
	int				*size;
}					t_mlx_struct;

int		            *count_size(int fd);
int					rot_g_onkey(int keycode, t_mlx_struct *coords_ptr);
double				***make_3d_array(int fd, int *size);
t_3d_coords			*create_3d_coords(double *coords);
t_coords			*create_coords(int x0, int y0, int x1, int y1);
t_cube_coords       *create_cube_coords(t_3d_coords *top_left);
t_mlx_struct		*create_mlx_struct(void *mlx_ptr, void *win_ptr, t_coords *coords, void *payload, int *size);
t_rgb				*hex_to_rgb(int hex);
t_rgb				*create_rgb_struct(int r, int g, int b);
void        		draw_cube(t_cube_coords *cube_coords, t_mlx_struct *mlx);
void            	draw_grid(t_mlx_struct *mlx_ptr, double ***coords_arr, int *size);
void        		draw_line(t_3d_coords *p1, t_3d_coords *p2, t_mlx_struct *param);
void            	free_3d_array(t_mlx_struct *ptr);
void            	make_square(t_mlx_struct *param);
void		        rotate_cube_z(t_cube_coords *cube_coords, double angle);
void		        rotate_cube_x(t_cube_coords *cube_coords, double angle);
void		        rotate_cube_y(t_cube_coords *cube_coords, double angle);
void        		rot_grid(double ***coords_arr, int *size, double angle, char axel);
void		        rotate_x(t_3d_coords *coords, double angle);
void		        rotate_y(t_3d_coords *coords, double angle);
void		        rotate_z(t_3d_coords *coords, double angle);
void		        draw_axis(t_mlx_struct *mlx_ptr);


#endif
