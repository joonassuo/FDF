/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuonper <jsuonper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:28:32 by jsuonper          #+#    #+#             */
/*   Updated: 2020/02/24 15:52:09 by jsuonper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** Needed for malloc(), free() and write(). Also for typedef size_t and sizeof()
*/

# include <unistd.h>
# include <stdlib.h>

/*
** Macro for the buffer size, the max number of file descriptors available, and
** to get the correct return value from the gnl_read_file() function.
** Find the max number of files:
** Mac: launchctl limit maxfiles
** Linux: ulimit -n
*/

# define BUFF_SIZE 8
# define MAX_FD 1024 + 1
# define RET_VALUE(ret)	ret > 0 ? 1 : ret

/*
** Prototype for the get_next_line() function.
*/

int		get_next_line(int const fd, char **line);

#endif

/*
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# define FD_BUFF 4096

# include <unistd.h>
# include <stdlib.h>
# include "./libft.h"

int			get_next_line(const int fd, char **line);

#endif
*/