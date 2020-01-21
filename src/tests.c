#include "../includes/fdf.h"
#include <stdio.h>
#include <fcntl.h>

int					mouse_draw_line(int button, int x, int y, t_mlx_struct *param)
{
	if (!*(int*)param->payload)
	{
		*(int*)param->payload = 1;
		param->coords->x0 = x;
		param->coords->y0 = y;
		return (0);
	}
	else
	{
		*(int*)param->payload = 0;
		draw_line(param->coords->x0, param->coords->y0, x, y, param);
	}
	return (button);
}

int				rotate_on_key(int keycode, t_mlx_struct *cube_ptr) {
	double		angle;

	if (keycode == 126)
	{
		angle = 0.05;
		rotate_cube_x(cube_ptr->payload, angle);
		mlx_clear_window(cube_ptr->mlx_ptr, cube_ptr->win_ptr);
		draw_cube(cube_ptr->payload, cube_ptr->mlx_ptr);
	}
	else if (keycode == 125)
	{
		angle = -0.05;
		rotate_cube_x(cube_ptr->payload, angle);
		mlx_clear_window(cube_ptr->mlx_ptr, cube_ptr->win_ptr);
		draw_cube(cube_ptr->payload, cube_ptr->mlx_ptr);
	}
	else if (keycode == 124)
	{
		angle = 0.05;
		rotate_cube_y(cube_ptr->payload, angle);
		mlx_clear_window(cube_ptr->mlx_ptr, cube_ptr->win_ptr);
		draw_cube(cube_ptr->payload, cube_ptr->mlx_ptr);
	}
	else if (keycode == 123)
	{
		angle = -0.05;
		rotate_cube_y(cube_ptr->payload, angle);
		mlx_clear_window(cube_ptr->mlx_ptr, cube_ptr->win_ptr);
		draw_cube(cube_ptr->payload, cube_ptr->mlx_ptr);
	}
	else if (keycode == 43)
	{
		angle = 0.05;
		rotate_cube_z(cube_ptr->payload, angle);
		mlx_clear_window(cube_ptr->mlx_ptr, cube_ptr->win_ptr);
		draw_cube(cube_ptr->payload, cube_ptr->mlx_ptr);
	}
	else if (keycode == 47)
	{
		angle = -0.05;
		rotate_cube_z(cube_ptr->payload, angle);
		mlx_clear_window(cube_ptr->mlx_ptr, cube_ptr->win_ptr);
		draw_cube(cube_ptr->payload, cube_ptr->mlx_ptr);
	}
	
	return (keycode);
}

int					main(int ac, char **av)
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_coords		*coords_ptr;
//	t_3d_coords		*cube_center;
//	t_cube_coords	*cube_coords;
	t_mlx_struct	*struct_ptr;
//	t_mlx_struct	*cube_ptr;
	int				mouse_clicked;
	int				fd;
	int				i;
	int				j;
	double			angle;

	mouse_clicked = 0;
	angle = 0.05;

	// initialize mlx window
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");

	// draw line on mouse click
	coords_ptr = create_coords(0, 0, 0, 0);
	struct_ptr = create_mlx_struct(mlx_ptr, win_ptr, coords_ptr, &mouse_clicked);
	mlx_mouse_hook(win_ptr, mouse_draw_line, struct_ptr);

/* 
	// draw cube
	cube_center = create_3d_coords(250, 250, 0);
	cube_coords = create_cube_coords(cube_center);
	draw_cube(cube_coords, mlx_ptr);

	// rotate on keypress
	cube_ptr = create_mlx_struct(mlx_ptr, win_ptr, 0, cube_coords);
	mlx_key_hook(win_ptr, rotate_on_key, cube_ptr);
	
	mlx_loop(mlx_ptr);

 */





	// MAKE GRID:

 	int				*size;
	int				***coords_arr;

	fd = open(av[1], O_RDONLY);
	size = count_size(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	coords_arr = make_3d_array(fd, size);
	

	
	draw_grid(mlx_ptr, coords_arr);
	mlx_loop(mlx_ptr);

	return (ac);
}