#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define MAX_FD 1024
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
