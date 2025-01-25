/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:09:41 by davihako          #+#    #+#             */
/*   Updated: 2025/01/25 21:35:57 by davihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_buff(char	*buff1, char *buff2)
{
	char	*res;

	res = ft_strjoin(buff1, buff2);
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
	line = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buff[i])
		line[j++] = buff[i++];
	free(buff);
	return (line);
}

char	*buff_line(char *buff)
{
	int		count;
	char	*res;

	count = 0;
	while(buff[count] && buff[count] != '\n')
		count++;
	res = ft_calloc(count + 2, 1);
	count = 0;
	while (buff[count] && buff[count] != '\n')
	{
		res[count] = buff[count];
		count++;
	}
	if (buff[count] && buff[count] == '\n')
		res[count] = '\n';
	return (res);
}

char	*read_file(int fd, char *res)
{
	char	*buff;
	int		bytes;

	if (!res)
		ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE, 1);
	bytes = read(fd, buff, BUFFER_SIZE);
	while (bytes)
	{
		if (!bytes)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		res = free_buff(res, buff);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (BUFFER_SIZE <= 0|| fd == -1 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = read_file(fd, buff);
	if (!buff)
		return (NULL);
	line = buff_line(buff);
	buff = next(buff);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main(){
	int fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
