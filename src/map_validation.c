/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:43:46 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/12 15:31:40 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int				char_validation(char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] > '9' || line[i] < '0')
		&& (line[i] != '-' && line[i] != ' '))
			return (-1);
		i++;
	}
	return (0);
}

void			validate_map(int fd)
{
	char		*line;
	char		**c_arr;
	int			ref_count;
	int			i;

	ref_count = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (char_validation(line) == -1)
			handle_error("ERROR: map not valid");
		i = 0;
		c_arr = ft_strsplit(line, ' ');
		while (c_arr[i])
		{
			free(c_arr[i]);
			i++;
		}
		if (ref_count == 0)
			ref_count = i;
		if (i != ref_count)
			handle_error("ERROR: map not valid");
		free(c_arr);
		free(line);
	}
}
