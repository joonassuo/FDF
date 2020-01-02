/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:19:25 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/02 15:30:43 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_pixel_put(mlx_ptr, win_ptr, 10, 10, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 11, 10, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 12, 10, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 13, 10, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 14, 10, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 15, 10, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 16, 10, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 10, 11, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 11, 11, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 12, 11, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 13, 11, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 14, 11, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 15, 11, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 16, 11, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 10, 12, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 11, 12, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 12, 12, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 13, 12, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 14, 12, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 15, 12, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 16, 12, 255);
	mlx_pixel_put(mlx_ptr, win_ptr, 10, 13, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 11, 13, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 12, 13, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 13, 13, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 14, 13, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 15, 13, 100);
	mlx_pixel_put(mlx_ptr, win_ptr, 16, 13, 100);
	mlx_loop(mlx_ptr);
	return (0);
}
