/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:48:52 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/11 12:54:35 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIN_H 1000
# define WIN_W 1500
# define Z_CHANGE 10
# define LINE_BUFF 1000
# include "../miniLibX/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct		s_loopers
{
	int				i;
	int				j;
	int				k;
	char			*value;
	double			number;
	int				start;
	int				ret;
}					t_loopers;

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
	double			***coords_arr;
	double			***og_arr;
	double			total_x;
	double			total_y;
	double			total_z;
	int				*size;
	int				grid_size;
	int				fd;
}					t_mlx_struct;

typedef struct		s_line_data
{
	int				e2;
	t_coords		*coords;
	t_helpers		*helpers;
}					t_line_data;

int		            *count_size(int fd);
int					key_handlers(int keycode, t_mlx_struct *data_ptr);
double				***make_grid(t_mlx_struct *data_ptr);
t_3d_coords			*create_3d_coords(double *coords);
t_coords			*create_coords(int x0, int y0, int x1, int y1);
t_mlx_struct		*create_mlx_struct(void);
t_rgb				*hex_to_rgb(int hex);
t_rgb				*create_rgb_struct(int r, int g, int b);
void				handle_error(char *msg);
void            	draw_grid(t_mlx_struct *data_ptr);
void        		draw_line(t_3d_coords *p1, t_3d_coords *p2, t_mlx_struct *param);
void            	make_square(t_mlx_struct *param);
void        		rot_grid(t_mlx_struct *data_ptr, double angle, char axel);
void		        draw_axis(t_mlx_struct *mlx_ptr);


#endif
