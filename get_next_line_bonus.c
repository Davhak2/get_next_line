/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:49:23 by davihako          #+#    #+#             */
/*   Updated: 2025/01/26 14:49:23 by davihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_buff(char *buff1, char *buff2)
{
	char	*res;

	res = ft_strjoin(buff1, buff2);
	if (!res)
	{
		free(buff1);
		return (NULL);
	}
	free(buff1);
	return (res);
}

char	*next(char *buff)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buff) - i, sizeof(char));
	if (!line)
	{
		free(buff);
		return (NULL);
	}
	i++;
	j = 0;
	while (buff[i])
		line[j++] = buff[i++];
	line[j] = '\0';
	free(buff);
	return (line);
}

char	*buff_line(char *buff)
{
	int		count;
	char	*res;

	count = 0;
	while (buff[count] && buff[count] != '\n')
		count++;
	if (buff[count] == '\n')
		res = ft_calloc(count + 2, sizeof(char));
	else
		res = ft_calloc(count + 1, sizeof(char));
	if (!res)
		return (NULL);
	count = 0;
	while (buff[count] && buff[count] != '\n')
	{
		res[count] = buff[count];
		count++;
	}
	if (buff[count] == '\n')
		res[count] = '\n';
	return (res);
}

char	*read_file(int fd, char *res)
{
	char	*buff;
	int		bytes;

	if (!res)
		res = ft_calloc(1, sizeof(char));
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	bytes = read(fd, buff, BUFFER_SIZE);
	while (bytes > 0)
	{
		buff[bytes] = '\0';
		res = free_buff(res, buff);
		if (ft_strchr(buff, '\n'))
			break ;
		bytes = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (bytes < 0 || !res[0])
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff[fd] = read_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = buff_line(buff[fd]);
	buff[fd] = next(buff[fd]);
	return (line);
}
