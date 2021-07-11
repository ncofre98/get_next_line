/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:59:25 by ncofre            #+#    #+#             */
/*   Updated: 2021/07/10 20:18:52 by ncofre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static size_t		ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		has_return(const char *s)
{
	if (!s)
		return (0);
	while (*s)
		if (*s++ == '\n')
			return (1);
	return (0);
}

static	void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(char*)(s + i) = '\0';
		i++;
	}
}

void			*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	long int	total_size;

	total_size = nmemb * size;
	if (!(ptr = malloc(total_size)))
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

/* In this version of substr if fr == 1 then s will be freed at the end
** Everything else remains the same.
 */

static	char		*gnl_substr(char *s, unsigned int start, size_t len, int fr)
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

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

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

char		*gnl_strjoin(char *dst, char const *src)
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

char		*get_line(char **rem)
{
	size_t end;
	char *line;
	char *tmp;

	end = 0;
	tmp = *rem;
	while (tmp[end] && tmp[end] != '\n')
		end++;
	line = gnl_substr(*rem, 0, ++end, 0);
	if (!has_return(*rem))
		free_null(rem);
	else
		*rem = gnl_substr(*rem, end, ft_strlen(*rem) - end, 1);
	return (line);
}
