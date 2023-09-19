/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:40:03 by arlee             #+#    #+#             */
/*   Updated: 2023/09/19 20:18:45 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_save(char *save)
{
	char	*next_save;
	int		i;
	int		j;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	next_save = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!next_save)
	{
		free(save);
		return (NULL);
	}
	i++;
	j = 0;
	while (save[i] != '\0')
		next_save[j++] = save[i++];
	next_save[j] = '\0';
	free(save);
	return (next_save);
}

char	*get_one_line(char *save, char *str)
{
	int	i;

	i = 0;
	while (save[i] != '\0' && save [i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_one_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (*save == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
	{
		free(save);
		return (NULL);
	}
	str = get_one_line(save, str);
	return (str);
}

char	*ft_read(int fd, char *save, int read_return)
{
	char	*buff;
	char	*prev;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL); 
	while (( read_return = read(fd, buff, BUFFER_SIZE)) > 0 )
	{
		buff[read_return] = '\0';
		prev = save;
		if (!prev)
			prev = ft_strdup("");
		save = ft_strjoin(prev, buff);
		free(prev);
		if (!save)
		{
			free(buff);
			return (NULL);
		}
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	free(buff);
	if (read_return == -1 || (read_return == 0 && !save))
	{
		free(save);
		return (NULL);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	int			read_return;

	read_return = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save, read_return);
	if (!save)
		return (NULL);
	line = ft_one_line(save);
	save = ft_next_save(save);
	return (line);
}
