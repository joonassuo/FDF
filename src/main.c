/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/02 17:46:46 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					draw_line(int button, int x, int y, t_mlx_struct *param)
{
	int				i;

	i = 0;
	while (i++ < 100)
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x + i, y, 0xFFFFFF);
   return (button);	
}

int					test_func(int key, t_mlx_struct *param)
{
	int				i;

	i = 0;
	while (i < 100)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, i, 20, 0xFFFFFF);
		i++;
	}
	return (key);
}

int					main(void)
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlx_struct	*struct_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	struct_ptr = create_mlx_struct(mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, test_func, struct_ptr);
	mlx_mouse_hook(win_ptr, draw_line, struct_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
