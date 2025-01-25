/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:07:54 by davihako          #+#    #+#             */
/*   Updated: 2025/01/25 21:43:40 by davihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	s_len;
	char	letter;

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

	str1 = str;
	while (*str)
		str++;
	return (str - str1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		size;
	char	*res;
	char	*start;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (size + 1));
	start = res;
	if (!res || !s1 || !s2)
		return (NULL);
	while (*s1)
		*(res++) = *(s1++);
	while (*s2)
		*(res++) = *(s2++);
	res[size] = '\0';
	return (res);
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
	size_t	total;
	void	*ptr;

	total = count * size;
	if (count && total / count != size)
		return (NULL);
	ptr = malloc(total);
	if (ptr)
		ft_memset(ptr, 0, total);
	return (ptr);
}
