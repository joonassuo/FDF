/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:19:08 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/07 18:19:31 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

t_rgb			*create_rgb_struct(int r, int g, int b)
{
	t_rgb		*rgb;

	if (!(rgb = (t_rgb*)malloc(sizeof(t_rgb))))
		return (0);
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return (rgb);
}

t_rgb			*hex_to_rgb(int hex)
{
	t_rgb		*rgb;
	int			r;
	int			g;
	int			b;

	r = ((hex >> 16) & 0xFF);
	g = ((hex >> 8) & 0xFF);
	b = (hex & 0xFF);
	rgb = create_rgb_struct(r, g, b);
	return (rgb);
}