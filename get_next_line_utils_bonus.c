#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	s_len;
	char	letter;

	if (!s)
		return (NULL);
	letter = (char)c;
	s_len = ft_strlen(s) + 1;
	while (s_len--)
	{
		if (*s == letter)
			return ((char *)s);
		++s;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	const char	*str1;

	if (!str)
		return (0);
	str1 = str;
	while (*str)
		str++;
	return (str - str1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		size;
	char	*res;
	char	*start;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	start = res;
	if (s1)
		while (*s1)
			*(res++) = *(s1++);
	if (s2)
		while (*s2)
			*(res++) = *(s2++);
	*res = '\0';
	return (start);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem;

	mem = (unsigned char *)b;
	while (len--)
		*mem++ = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(1));
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
