/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncofre <ncofre@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:59:25 by ncofre            #+#    #+#             */
/*   Updated: 2021/06/10 21:37:22 by ncofre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static	void    *ft_memcpy(void *dest, const void *src, size_t n)
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


/* In this version of strlen, if ln == 0 works as usual,
** otherwise it will count before the '\n' character is reached.
** Everything else remains the same.
*/

static	size_t          gnl_strlen(const char *s, int ln)
{
	size_t i;

	i = 0;
	if (ln)
		while (s && s[i] && s[i] != '\n')
			i++;
	else
		while (s && s[i])
			i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (c == '\0')
		return ((char*)&s[gnl_strlen(s, 0)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}

static int	char_after_nline(const char *str)
{
	int i;
	int c;

	i = -1;
	c = -1;
	while (str[++i])
		if (str[i] == '\n')
			break;
	while (str[++i])
		if (str[i] != '\n')
		{
			c = i;
			break;
		}
	return (c);
}

/* In this version of strjoin, if ln != 0, the length of src will
** be counted before '\n' is reached.
** The joined string will be a combination of the complete string of dst and
** the first src_len bytes of src.
** dst will be freed at the end.
** Everything else remains the same.
*/

char		*gnl_strjoin(char *dst, char const *src, int ln)
{
	char	*ptr;
	size_t	dst_len;
	size_t	src_len;

	dst_len = gnl_strlen(dst, 0);
	if (ln)
		src_len = gnl_strlen(src, 1);
	else
		src_len = gnl_strlen(src, 0);
	ptr = (char*)malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, dst, dst_len + 1);
	ft_memcpy(&(ptr[dst_len]), src, src_len);
	ptr[dst_len + src_len + 1] = '\0';
	free(dst);
	return (ptr);
}

/*
**Returns 1 if any character different from '\n' is found in the string,
**Returns 2 if there are at least one character before the newline,
**otherwise it returns 0.
*/

static	int	gnl_haschars(char *str)
{
	int	ch;

	ch = 0;
	while (*str)
	{
		if (*str == '\n' && !ch)
			break;
		if (*str != '\n')
			ch = 1;
		if (*str++ == '\n' && ch == 1)
		{
			ch = 2;
			break;
		}
	}
	return (ch);
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
	if (start >= gnl_strlen(s, 0))
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

void		gnl_check_and_or_join(char **buf, char **rem, char **line)
{
	int	ret;
	int	ch_pos;

	ret = gnl_haschars(*buf);
	if (ret == 0 || ret == 1)
		*rem = *buf;
	else if (ret == 2)
	{
		*line = gnl_strjoin(*line, *buf, 1);
		ch_pos = char_after_nline(*buf);
		*rem = gnl_substr(*buf, ch_pos, gnl_strlen(*buf, 0) - ch_pos + 1, 1);
	}
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
	*line = gnl_substr(*rem, start, end++ - start, 0);
	if (*rem + end && gnl_haschars(&(*(*rem + end))))
		*rem = gnl_substr(*rem, end, gnl_strlen(*rem, 0) - end, 1);
	else
	{
		free(*rem);
		*rem = NULL;
	}
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
