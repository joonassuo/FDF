/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:30:08 by jsuonper          #+#    #+#             */
/*   Updated: 2020/01/20 14:04:23 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static int			trim_line(char **str, char **line)
{
	size_t			line_len;
	char			*tmp;

	line_len = 0;
	while ((*str)[line_len] != '\n' && (*str)[line_len] != '\0')
		line_len++;
	if ((*str)[line_len] == '\n')
	{
		*line = ft_strsub(*str, 0, line_len);
		tmp = ft_strdup(&((*str)[line_len + 1]));
		free(*str);
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int			output_value(char **res, int fd, char **line, int read_sz)
{
	if (read_sz < 0)
		return (-1);
	else if (read_sz == 0 && res[fd] == NULL)
		return (0);
	else
		return (trim_line(&res[fd], line));
}

int					get_next_line(const int fd, char **line)
{
	static char		*res[FD_BUFF];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				read_sz;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((read_sz = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_sz] = '\0';
		if (res[fd] == NULL)
			res[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(res[fd], buff);
			free(res[fd]);
			res[fd] = tmp;
		}
		if (ft_strchr(res[fd], '\n'))
			break ;
	}
	return (output_value(res, fd, line, read_sz));
}
