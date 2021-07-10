/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:00:24 by ncofre            #+#    #+#             */
/*   Updated: 2021/07/10 13:50:07 by ncofre           ###   ########.fr       */
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

	ret = 1;
	free_null(line);
	if (BUFFER_SIZE <= 0 || fd < 0 || !(buf = ft_calloc(1, BUFFER_SIZE + 1)))
		return (-1);
	while (!has_return(rem) && ret != 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		rem = gnl_strjoin(rem, buf);
	}
	*line = get_line(&rem);
	free(buf);
	if (ret > 0)
		return (1);
	return (ret);
}
