#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

char    *get_left(char *line);
char	*ft_join(char *left, char *buff);
int		ft_strlen(char *str);
int		ft_strsrc(char *str, char c);
char	*clean_line(char *line);
char	*get_next_line(int fd);
char	*read_buff(int fd, char *line);

#endif