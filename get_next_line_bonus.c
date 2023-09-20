/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 07:09:48 by aaaaaran          #+#    #+#             */
/*   Updated: 2023/09/21 07:18:11 by aaaaaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next_save(char *save)
{
	char	*next_save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	next_save = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!next_save)
		return (NULL);
	i++;
	while (save[i])
		next_save[j++] = save[i++];
	next_save[j] = '\0';
	free(save);
	return (next_save);
}

char	*ft_one_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_read(int fd, char *save)
{
	char	*buff;
	int		read_return;

	read_return = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!(ft_strchr(save, '\n')) && read_return)
	{
		read_return = read(fd, buff, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(save);
			free(buff);
			return (NULL);
		}
		buff[read_return] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[8192];
	char		*line;

	if (fd < 0 || fd > 8192 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_read(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_one_line(save[fd]);
	save[fd] = ft_next_save(save[fd]);
	return (line);
}
