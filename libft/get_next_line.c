/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:30:08 by jsuonper          #+#    #+#             */
/*   Updated: 2020/03/11 17:17:28 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int		ft_read_fd(const int fd, char **str)
{
	int		rt;
	char	buff[BUFF_SIZE + 1];
	char	*str_temp;

	rt = 0;
	if (!str[fd] && (rt = read(fd, buff, BUFF_SIZE)))
	{
		if (rt == -1)
			return (rt);
		buff[rt] = '\0';
		str[fd] = ft_strdup(buff);
	}
	if (rt == 0 && !str[fd])
		return (0);
	while (!ft_strchr(str[fd], '\n') && (rt = read(fd, buff, BUFF_SIZE)))
	{
		if (rt == -1)
			return (rt);
		buff[rt] = '\0';
		str_temp = ft_strjoin(str[fd], buff);
		ft_strdel(&str[fd]);
		str[fd] = str_temp;
	}
	return (rt);
}

static int		ft_crop_to_line(const int fd, int rt, char **str, char **line)
{
	char	*ptr_t;

	if (rt == 0 && str[fd] && str[fd][0] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		return (0);
	}
	if (rt == 0 && str[fd] && !ft_strchr(str[fd], '\n'))
	{
		*line = ft_strdup(str[fd]);
		str[fd][0] = '\0';
		return (1);
	}
	if (str[fd] && ft_strchr(str[fd], '\n'))
	{
		*line = ft_strsub(str[fd], 0, (ft_strchr(str[fd], '\n') - str[fd]));
		ptr_t = str[fd];
		str[fd] = ft_strdup(ft_strchr(str[fd], '\n') + 1);
		ft_strdel(&ptr_t);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[MAX_FD];
	int				rt;
	
	if (fd < 0 || fd > MAX_FD || BUFF_SIZE < 1 || !line)
	{
		return (-1);
	}
	rt = ft_read_fd(fd, str);
	if (rt == -1)
		return (-1);
	return (ft_crop_to_line(fd, rt, str, line));
}


/*
#include "./get_next_line.h"
#include <stdio.h>

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
	printf("get next line\n");
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
*/