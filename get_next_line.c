/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:09:27 by epaksoy           #+#    #+#             */
/*   Updated: 2023/08/07 15:30:44 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_left(char *line)
{
	int		a;
	int		b;
	char	*ret;

	a = 0;
	while (line[a] && line[a] != '\n')
		a++;
	if (!line[a])
		return (NULL);
	a++;
	b = ft_strlen(line) - a;
	ret = malloc(sizeof(char) * (b + 1));
	b = 0;
	while (line[a])
	{
		ret[b] = line[a];
		b++;
		a++;
	}
	ret[b] = '\0';
	return (ret);
}

char	*read_buff(int fd, char *line)
{
	char	*buff;
	int		buff_size;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	buff_size = 1;
	while (!ft_strsrc(line, '\n') && buff_size != 0)
	{
		buff_size = read(fd, buff, BUFFER_SIZE);
		if (buff_size == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[buff_size] = '\0';
		line = ft_join(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = read_buff(fd, left_str);
	if (!left_str)
		return (NULL);
	line = clean_line(left_str);
	left_str = get_left(left_str);
	return (line);
}
