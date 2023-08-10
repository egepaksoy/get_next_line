/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:38:18 by epaksoy           #+#    #+#             */
/*   Updated: 2023/08/10 17:38:19 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int k)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!k)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == k)
			return ((char *)str + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *data)
{
	unsigned int	i;
	unsigned int	j;
	char			*s3;

	if (!data)
		return (NULL);
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	s3 = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(data) + 1));
	if (!s3)
		return (free(line), NULL);
	i = -1;
	while (line[++i] != '\0')
		s3[i] = line[i];
	j = -1;
	while (data[++j] != '\0')
		s3[i + j] = data[j];
	s3[i + j] = '\0';
	free(line);
	return (s3);
}
