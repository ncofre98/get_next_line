#ifndef GNL_H
# define GNL_H

#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
