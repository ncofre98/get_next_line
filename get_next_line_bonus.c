/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:30:10 by ncofre            #+#    #+#             */
/*   Updated: 2021/07/17 20:03:37 by ncofre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
**Returns a pointer to the first ocurrence of the character c in
**the string s.
**
**Returns NULL if the character is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/*
**Erases the data in the n bytes of the memory starting
**at the location pointed to by s, by writing zeros (bytes containing '\0')
**to that area.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
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
	static char	*rem[MAX_FD];
	char		*buf;
	int			ret;

	ret = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= MAX_FD)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!(ft_strchr(rem[fd], '\n')) && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		if (ret != 0)
			rem[fd] = gnl_strjoin(rem[fd], buf);
	}
	free(buf);
	return (get_line(&rem[fd]));
}
