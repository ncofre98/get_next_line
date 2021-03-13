/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:00:24 by ncofre            #+#    #+#             */
/*   Updated: 2021/03/13 12:32:41 by ncofre           ###   ########.fr       */
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
	static char 	*buf;
	int			ret;
	unsigned int	i;

	if (!buf)
		if (!(buf = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	i = 0;
	while (buf[i])
	{
		if (buf[i] != '\n')
			(&(**line))[i] = buf[i];
		i++;
	}
	(&(**line))[i] = '\0';
	if (ret > 0)
		return (1);
	if (ret == 0)
		free(buf);
	return (ret);
}
