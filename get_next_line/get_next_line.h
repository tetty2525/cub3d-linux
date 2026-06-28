/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htate <htate@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:01:56 by htate             #+#    #+#             */
/*   Updated: 2026/06/28 17:02:12 by htate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *left_str, char *buff);
void	*gnl_calloc(size_t nmemb, size_t size);
size_t	gnl_strlen(const char *str);
char	*make_line(char *txt);
char	*find_newline(int fd, char *str);
char	*next_text(char *text);
char	*get_next_line(int fd);

#endif
