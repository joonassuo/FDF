/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:48:52 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/10 12:54:34 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define GRID_SZ 40
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

typedef struct		s_mlx_struct
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			***coords;
	int				*size;
}					t_mlx_struct;

int		            *count_size(int fd);
int					rot_g_onkey(int keycode, t_mlx_struct *coords_ptr);
double				***make_3d_array(int fd, int *size);
t_3d_coords			*create_3d_coords(double *coords);
t_coords			*create_coords(int x0, int y0, int x1, int y1);
t_mlx_struct		*create_mlx_struct(void *mlx_ptr, void *win_ptr, double ***coords, int *size);
t_rgb				*hex_to_rgb(int hex);
t_rgb				*create_rgb_struct(int r, int g, int b);
void            	draw_grid(t_mlx_struct *mlx_ptr, double ***coords_arr, int *size);
void        		draw_line(t_3d_coords *p1, t_3d_coords *p2, t_mlx_struct *param);
void            	make_square(t_mlx_struct *param);
void        		rot_grid(double ***coords_arr, int *size, double angle, char axel);
void		        rotate_x(t_3d_coords *coords, double angle);
void		        rotate_y(t_3d_coords *coords, double angle);
void		        rotate_z(t_3d_coords *coords, double angle);
void		        draw_axis(t_mlx_struct *mlx_ptr);


#endif
