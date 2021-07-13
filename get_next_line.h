#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_strjoin(char *dst, char const *src);
char	*get_line(char **rem);
void	ft_bzero(void *s, size_t n);
int		has_return(const char *s);

#endif
