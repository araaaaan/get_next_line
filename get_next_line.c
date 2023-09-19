/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:40:03 by arlee             #+#    #+#             */
/*   Updated: 2023/09/19 22:18:56 by aaaaaran         ###   ########.fr       */
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
	{
		next_save[j] = save[i];
		j++;
		i++; 
	}
	next_save[j] = '\0';
	free(save);
	return (next_save);
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
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
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

// char	*ft_read(int fd, char *save)
// {
// 	int		read_return;
// 	char	*buff;
// 	char 	*prev;

// 	read_return = 1;
// 	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buff)
// 		return (NULL);
// 	while (read_return != 0)
// 	{
// 		read_return = read(fd, buff, BUFFER_SIZE);
// 		if (read_return == -1)
// 		{
// 			free(save);
// 			return (NULL);
// 		}
// 		buff[read_return] = '\0';
// 		prev = save;
// 		if (!prev)
// 			prev = ft_strdup("");
// 		save = ft_strjoin(prev, buff);
// 		if(!save)
// 		{
// 			free(prev);
// 			return (NULL);
// 		}
// 		free(prev);
// 		if (ft_strchr(buff, '\n') != NULL)
// 			break ;
// 	}
// 	free(buff);
// 	return (save);
// }

char *ft_read(int fd, char *save)
{
	int read_return;
	char *buff;
	char *prev;
	char *temp;

	read_return = 0;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while ((read_return = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_return] = '\0';
		prev = save;
		if (!prev)
			prev = ft_strdup("");
		temp = ft_strjoin(prev, buff);
		free(prev);
		if (!temp)
		{
			free(buff);
			return (NULL);
		}
		save = temp;
		if (ft_strchr(buff, '\n') != NULL)
			break;
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
	static char		*save;
	char			*line;

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
//     int fd = open("test.txt", O_RDONLY);
// 	int i;
// 	char buffer[1024];
// 	i = 0;
//     if (fd == -1)
//     {
//         perror("파일 열기 실패");
//         return 1;
//     }


//     while( i < 10 )
//     {
// 	    printf("contents :::[%d], %s\n" , i, get_next_line(fd));
//         i++;
//     }
//     // char *line;
//     // while ((line = get_next_line(fd)) != NULL)
//     // {
//     //     // 한 줄을 처리 (예: 출력)
//     //     printf("라인: %s\n", line);
//     //     free(line);
//     // }

//     close(fd);
//     return 0;
// }