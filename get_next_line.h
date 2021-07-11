#ifndef GNL_H
# define GNL_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int	has_return(const char *s);
char	*gnl_strjoin(char *dst, char const *src);
char	*get_line(char **rem);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
