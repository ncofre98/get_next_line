/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:00:24 by ncofre            #+#    #+#             */
/*   Updated: 2021/04/07 17:10:33 by ncofre           ###   ########.fr       */
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

void	ft_getfline(char *rem, char **line)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	while (rem[i])
	{
		if (!start && rem[i] != '\n')
			start = i;
		else
		{
		}
}



int				get_next_line(int fd, char **line)
{
	static char	*rem;
	char			*buf;
	int			ret;

	if (rem)
	{
		*line = ft_substr(rem, 0, ft_fnewline(rem));
		buf.tmp = rem;
		rem = ft_substr()
	}
	else
	{
		if (!(buf = scmalloc(BUFFER_SIZE + 1))))
			return (-1);
		while ((ret = buf(fd, buf, BUFFER_SIZE)) >= 0 &&
		   (!(ft_strchr(buf, '\n'))))
		{
			buf.tmp = ft_strjoin(line, buf);
			free(line);
			line = buf.tmp;
		}
	}
	return (ft_ret(ret, line, buf, buf.tmp, rem));
}

int	ft_ret(int ret, char *line, char *read, char *tmp, static char *rem)
{
	if (line)
		free(line);
	if (read)
		free(read);
	if (tmp)
		free(tmp);
	if (ret == 0)
		free(rem);
	else if (ret > 0)
		return (1)
	else
		return (-1);
}
