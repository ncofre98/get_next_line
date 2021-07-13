/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:00:24 by ncofre            #+#    #+#             */
/*   Updated: 2021/07/13 05:14:13 by ncofre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**This function checks if there are any \n in the string and returns 1.
**Otherwise it returns 0.
*/

int	has_return(const char *s)
{
	if (!s)
		return (0);
	while (*s)
		if (*s++ == '\n')
			return (1);
	return (0);
}

/*
**This function erases the data in the n bytes of the memory starting
**at the location pointed to by s, by writing zeros (bytes containing '\0')
**to that area.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char*)(s + i) = '\0';
		i++;
	}
}

/*
**DESCRIPTION:
** Write a function which returns a line read from a file descriptor.
**PARAMETERS:
** File descriptor to read from
**RETURN VALUE:
** Read line: correct behavior
** NULL: nothing else to read or an error ocurred
**IMPORTANT:
** You should always return the line that has been read followed by a '\n'
** unless you have reached end of file and there is no '\n'.
*/

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*buf;
	int			ret;

	ret = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!has_return(rem) && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		rem = gnl_strjoin(rem, buf);
	}
	free(buf);
	if (ret == 0)
		return (NULL);
	return (get_line(&rem));
}
