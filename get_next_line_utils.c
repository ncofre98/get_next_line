/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:59:25 by ncofre            #+#    #+#             */
/*   Updated: 2021/07/16 18:26:01 by ncofre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**Returns the length of the string in bytes.
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
**Allocates with malloc and returns a substring from the string s.
**The substring begins at index start and is of maximum size len.
**If fr == 1 then s will be freed at the end.
**Returns NULL if the allocation fails.
*/

static	char	*gnl_substr(char *s, unsigned int start, size_t len, int fr)
{
	char			*ptr;
	unsigned int	end;
	unsigned int	i;

	ptr = (char*)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	if (start >= ft_strlen(s))
		ft_bzero(ptr, len + 1);
	else
	{
		i = 0;
		end = start + len - 1;
		while (start <= end && len > 0)
		{
			ptr[i] = s[start];
			i++;
			start++;
		}
		ptr[i] = '\0';
		if (fr == 1 && *s)
			free(s);
	}
	return (ptr);
}

/*
**This function copies n bytes from memory area src to memory area
**dest. The memory areas must not overlap. Use ft_memmove() if the
**memory areas do overlap.
*/

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*(char*)(dest + i) = *(char*)(src + i);
		i++;
	}
	return (dest);
}

/*
**Allocates with malloc and returns a new string, which is the result of the
**concatenation of s1 and s2.
**
**Returns NULL if the allocation fails.
*/

char	*gnl_strjoin(char *dst, char const *src)
{
	char	*ptr;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	ptr = (char*)malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!ptr)
		return (NULL);
	if (dst_len > 0)
		ft_memcpy(ptr, dst, dst_len + 1);
	ft_memcpy(&(ptr[dst_len]), src, src_len);
	ptr[dst_len + src_len] = '\0';
	free(dst);
	return (ptr);
}

/*
**Finds (if there is any) the first ocurrence of '\n'
**and returns a freeable substring from 0 up to that byte.
**
**If there is any other '\n' after that, then it puts the remaining
**in *rem, freeing the old *rem.
**Otherwise it frees rem.
*/

char	*get_line(char **rem)
{
	size_t	end;
	char	*line;
	char	*tmp;

	tmp = *rem;
	if (!tmp)
		return (NULL);
	end = 0;
	while (tmp[end] && tmp[end] != '\n')
		end++;
	line = gnl_substr(*rem, 0, ++end, 0);
	if (end + 1 > ft_strlen(*rem))
	{
		free(*rem);
		*rem = NULL;
	}
	else
		*rem = gnl_substr(*rem, end, ft_strlen(*rem) - end, 1);
	return (line);
}
