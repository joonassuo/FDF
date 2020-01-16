/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:30:08 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/16 11:46:22 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void        draw_square(int tl[2], int tr[2], int bl[2], int br[2], t_mlx_struct *param)
{
    draw_line(tl[0], tl[1], tr[0], tr[1], param);
    draw_line(tl[0], tl[1], bl[0], bl[1], param);
    draw_line(br[0], br[1], tr[0], tr[1], param);
    draw_line(br[0], br[1], bl[0], bl[1], param);
}

void        make_square(t_mlx_struct *param)
{
    int     coords[8] = {
        200,
        200,
        300,
        200,
        200,
        300,
        300,
        300
    };

    double  angle = 0.5;
    int     temp;
    int     i = 0;

    while (i < 8)
    {
        temp = coords[i];
        coords[i] = coords[i] * cos(angle) - coords[i + 1] * sin(angle);
        coords[i + 1] = coords[i + 1] * cos(angle) + temp * sin(angle);
        i += 2;
    }

    int     tl[2] = {coords[0], coords[1]};
    int     tr[2] = {coords[2], coords[3]};
    int     bl[2] = {coords[4], coords[5]};
    int     br[2] = {coords[6], coords[7]};
    
    draw_square(tl, tr, bl, br, param);
}