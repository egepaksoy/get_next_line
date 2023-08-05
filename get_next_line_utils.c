#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_join(char *left, char *buff)
{
	int		tot;
	int		a;
	int		b;
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
	ret = malloc(ft_strlen(left) + ft_strlen(buff) + 1);
	a = 0;
	tot = 0;
	while (left[a])
	{
		ret[tot] = left[a];
		tot++;
		a++;
	}
	b = 0;
	while (buff[b])
	{
		ret[tot] = buff[b];
		tot++;
		b++;
	}
	ret[tot] = '\0';
	return (ret);
}

int		ft_strsrc(char *str, char c)
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