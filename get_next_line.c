#include "get_next_line.h"

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