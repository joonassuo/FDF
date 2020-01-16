/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:29:47 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/16 13:59:26 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void        draw_cube(t_cube_coords *cube_coords, t_mlx_struct *mlx)
{
    draw_line (
        cube_coords->c1->x,
        cube_coords->c1->y,
        cube_coords->c2->x,
        cube_coords->c2->y,
        mlx
    );
    draw_line (
        cube_coords->c1->x,
        cube_coords->c1->y,
        cube_coords->c4->x,
        cube_coords->c4->y,
        mlx
    );
    draw_line (
        cube_coords->c1->x,
        cube_coords->c1->y,
        cube_coords->c5->x,
        cube_coords->c5->y,
        mlx
    );
    draw_line (
        cube_coords->c3->x,
        cube_coords->c3->y,
        cube_coords->c2->x,
        cube_coords->c2->y,
        mlx
    );
    draw_line (
        cube_coords->c3->x,
        cube_coords->c3->y,
        cube_coords->c4->x,
        cube_coords->c4->y,
        mlx
    );
    draw_line (
        cube_coords->c3->x,
        cube_coords->c3->y,
        cube_coords->c7->x,
        cube_coords->c7->y,
        mlx
    );
    draw_line (
        cube_coords->c8->x,
        cube_coords->c8->y,
        cube_coords->c4->x,
        cube_coords->c4->y,
        mlx
    );
    draw_line (
        cube_coords->c8->x,
        cube_coords->c8->y,
        cube_coords->c7->x,
        cube_coords->c7->y,
        mlx
    );
    draw_line (
        cube_coords->c8->x,
        cube_coords->c8->y,
        cube_coords->c5->x,
        cube_coords->c5->y,
        mlx
    );
    draw_line (
        cube_coords->c6->x,
        cube_coords->c6->y,
        cube_coords->c7->x,
        cube_coords->c7->y,
        mlx
    );
    draw_line (
        cube_coords->c6->x,
        cube_coords->c6->y,
        cube_coords->c2->x,
        cube_coords->c2->y,
        mlx
    );
    draw_line (
        cube_coords->c6->x,
        cube_coords->c6->y,
        cube_coords->c5->x,
        cube_coords->c5->y,
        mlx
    );
}