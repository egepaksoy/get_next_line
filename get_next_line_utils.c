/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:09:31 by epaksoy           #+#    #+#             */
/*   Updated: 2023/08/07 15:28:31 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	ft_strlcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	return (a);
}

char	*ft_join(char *left, char *buff)
{
	int		a;
	int		tot;
	char	*ret;

	if (!left)
	{
		left = malloc(sizeof(char) * 1);
		if (!left)
			return (NULL);
		left[0] = '\0';
	}
	if (!left || !buff)
		return (NULL);
	tot = ft_strlen(left) + ft_strlen(buff);
	ret = malloc(tot + 1);
	if (!ret)
		return (NULL);
	a = ft_strlcpy(ret, left);
	ft_strlcpy(ret + a, buff);
	ret[tot] = '\0';
	return (ret);
}

int	ft_strsrc(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*clean_line(char *line)
{
	int		a;
	int		b;
	char	*ret;

	a = 0;
	while (line[a] && line[a] != '\n')
		a++;
	if (line[a] == '\n')
		a++;
	ret = malloc(sizeof(char) * (a + 1));
	b = 0;
	while (b < a)
	{
		ret[b] = line[b];
		b++;
	}
	ret[b] = '\0';
	return (ret);
}
