/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:55:03 by arlee             #+#    #+#             */
/*   Updated: 2023/09/21 07:07:27 by aaaaaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *save);
char	*ft_one_line(char *save);
char	*ft_next_save(char *save);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);

#endif