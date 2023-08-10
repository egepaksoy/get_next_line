/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:37:57 by epaksoy           #+#    #+#             */
/*   Updated: 2023/08/10 17:39:21 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_total_line(int fd, char *line);
char	*read_newline(char *line);
char	*before_line_delete(char *line);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int k);
char	*ft_strjoin(char *line, char *data);

#endif
