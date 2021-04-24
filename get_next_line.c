/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:00:24 by ncofre            #+#    #+#             */
/*   Updated: 2021/04/24 08:20:37 by ncofre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**DESCRIPTION:
**	Write a function which returns a line read from a file descriptor, without
**	the newline.
**PARAMETERS:
**	#1. File descriptor for reading.
**	#2. The value of what has been read.
**RETURN VALUE:
**	1: A line has been read.
**	0: EOF has been reached.
**	-1: An error happened.
*/

int				get_next_line(int fd, char **line)
{
	static char	*rem;
	char			*buf;
	int			ret;

	if (rem)
	{
		gnl_split(rem, line);
		ret = 1;
	}
	else
	{
		if (!(buf = scmalloc(BUFFER_SIZE + 1)))
			return (-1);
		while ((ret = read(fd, buf, BUFFER_SIZE)) >= 0 &&
		   (!(ft_strchr(buf, '\n'))))
			*line = gnl_strjoin(*line, buf);
		if (ft_strchr(buf, '\n'))
			rem = buf;
		else
			free(buf);
	}
	if (ret > 0)
		ret = 1;
	return (ret);
}
