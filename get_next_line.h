#ifndef GNL_H
# define GNL_H

#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_substr(char *s, unsigned int start, size_t len);
void	gnl_split(char *rem, char **line);
int	gnl_haschars(char *str);
char	*scmalloc(size_t size);

#endif
