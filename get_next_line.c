/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:00:24 by ncofre            #+#    #+#             */
/*   Updated: 2021/04/04 18:28:20 by ncofre           ###   ########.fr       */
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

/*
**This version of malloc allocates a char*, NUL-terminating the last byte
*/
char	*scmalloc(size_t size)
{
	char	*ptr;

	if (!(ptr = (char*)malloc(sizeof(char) * size)) || size <= 0)
		return (NULL);
	ptr[size - 1] = '\0';
	return (ptr);
}

int				get_next_line(int fd, char **line)
{
	t_buf			buf;
	static char	*rem;
	int			ret;

	if (!(buf.read = scmalloc(BUFFER_SIZE + 1)) || !(buf.line = scmalloc(1)))
			return (-1);
	if (rem && ft_strchr(rem, '\n'))
	{
		
	}
	else
		while ((ret = read(fd, buf.read, BUFFER_SIZE)) >= 0 &&
		   (!(ft_strchr(buf.read, '\n'))))
		{
			buf.tmp = ft_strjoin(buf.line, buf.read);
			free(buf.line);
			buf.line = buf.tmp;
		}
	ft_strlcpy(*line, buf.line, ft_strlen(buf.line) + 1);
	return (ft_ret(ret, buf.line, buf.read, buf.tmp, rem));
}

int	ft_splitrem(char *rem)
{
}

int	ft_ret(int ret, char *line, char *read, char *tmp, static char *rem)
{
	free(line);
	free(read);
	free(tmp);
	if (ret == 0)
		free(rem);
	else if (ret > 0)
		return (1)
	else
		return (-1);
}
