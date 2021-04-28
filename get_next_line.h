#ifndef GNL_H
# define GNL_H

#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line);
char	*gnl_strjoin(char *s1, char const *s2, int ln);
void	gnl_split(char **rem, char **line);
char	*scmalloc(size_t size);
char	*ft_strchr(const char *s, int c);

#endif
