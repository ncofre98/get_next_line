/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:00:24 by ncofre            #+#    #+#             */
/*   Updated: 2021/03/10 17:44:42 by ncofre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	unsigned int 	i;
	int	ret;

	if (!buf)
		buf = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	i = 0;
	ret = 1;
	while (buf[i] != '\n' && buf[i] != EOF && buf[i])
		i++;
	if (buf[i] == EOF)
		ret = 0;
	ft_strlcpy(*line, buf, BUFFER_SIZE + 1);
	if (ret == 0)
		free(buf);
	return (ret);
}
