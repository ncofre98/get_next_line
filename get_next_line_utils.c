/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:59:25 by ncofre            #+#    #+#             */
/*   Updated: 2021/04/27 19:47:59 by ncofre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(char*)(s + i) = '\0';
		i++;
	}
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(char*)(dest + i) = *(char*)(src + i);
		i++;
	}
	return (dest);
}

size_t          ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

size_t          ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t src_length;

	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_length);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size < dst_len)
		return (src_len + size);
	ft_strlcpy(dst + dst_len, src, size - dst_len);
	return (src_len + dst_len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (c == '\0')
		return ((char*)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}

char		*gnl_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, s1_len + s2_len + 1);
	free(s1);
	return (ptr);
}

char				*gnl_substr(char *s, unsigned int start, size_t len, int fr)
{
	char			*ptr;
	unsigned int	end;
	unsigned int	i;

	if (!(ptr = (char*)malloc(sizeof(char) * len + 1)))
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

static	void gnl_split_init(unsigned int *start, unsigned int *end)
{
	*start = 0;
	*end = 0;
}

void	gnl_split(char **rem, char **line)
{
	unsigned int	start;
	unsigned int	end;

	gnl_split_init(&start, &end);
	while (*(*rem + end))
		if (*(*rem + end++) != '\n')
		{
			start = --end;
			break;
		}
	while (*(*rem + ++end))
		if (*(*rem + end) == '\n')
			break;
	if (*line)
		free(*line);
	*line = gnl_substr(*rem, start, end++ - start, 0);
	if (*rem + end && gnl_haschars(&(*(*rem + end))))
		*rem = gnl_substr(*rem, end, ft_strlen(*rem) - end, 1);
	else
	{
		free(*rem);
		*rem = NULL;
	}
}

/*
**Returns 1 if any character different from '\n' is found in the string,
**Returns 2 if there are at least one character before the newline,
**otherwise it returns 0.
*/

int	gnl_haschars(char *str)
{
	int	ch;

	ch = 0;
	while (*str)
	{
		if (*str != '\n')
			ch = 1;
		if (*str++ == '\n' && ch == 1)
			ch = 2;
	}
	return (ch);
}

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
