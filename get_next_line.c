/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:00:24 by ncofre            #+#    #+#             */
/*   Updated: 2021/07/10 19:59:18 by ncofre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**DESCRIPTION:
**	Write a function which returns a line read from a file descriptor.
**PARAMETERS:
** File descriptor to read from
**RETURN VALUE:
** Read line: correct behavior
** NULL: nothing else to read or an error ocurred
**IMPORTANT:
** You should always return the line that has been read followed by a '\n'
** unless you have reached end of file and there is no '\n'.
*/

char				*get_next_line(int fd)
{
	static char	*rem;
	char			*buf;
	int			ret;

	ret = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || !(buf = ft_calloc(1, BUFFER_SIZE + 1)))
		return (NULL);
	while (!has_return(rem) && ret != 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
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
