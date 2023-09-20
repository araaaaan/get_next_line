/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:40:03 by arlee             #+#    #+#             */
/*   Updated: 2023/09/21 04:02:45 by aaaaaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_save(char *save)
{
	char	*next_save;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(save);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	next_save = (char *)malloc(sizeof(char) * (len - i + 1));
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
	while (!(ft_strchr(save, '\n')) && read_return > 0)
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
	static char	*save;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_one_line(save);
	save = ft_next_save(save);
	return (line);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int i;
// 	char *line;
// 	i = 0;
// 	if (fd == -1)
// 	{
// 		perror("파일 열기 실패");
// 		return 1;
// 	}

// 	while ((line = get_next_line(fd)) && i < 10)
// 	{
// 		printf("contents [%d]: %s\n", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return 0;
// }