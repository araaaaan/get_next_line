/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:40:03 by arlee             #+#    #+#             */
/*   Updated: 2023/09/13 20:36:05 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -Wall -Wextra -Werror  "-D BUFFER_SIZE=32" get_next_line.c get_next_line_utils.c

// fd를 받아와 해당 파일에서 개행으로 끝나는 한줄의 문장을 반환하는 함수

//#include "get_next_line.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 100


// int	check_fd(int fd)
// {
// 	if (fd == -1)
// 		return (0);
// 	else
// 		return (fd);
// }


// char	*get_next_line(int fd)
// {
// 	static char buff[BUFFER_SIZE]; 
// 	char *newline;
// 	// static : autoinitialize-> 0
// 	static int	size;
// 	static char	*save;
// 	int	len;
// 	int	buff_index;
// 	char	current;
// 	int i;

// 	i = 0;
// 	len = 0;
// 	buff_index = 0;
// 	current = 0;

// 	if (check_fd(fd) > 0)
// 	{
// 		size = (read(fd, buff, BUFFER_SIZE));
// 		//read all fd(data)
// 		if (size == -1) // read return size_t
// 			return (NULL);
// 	}
// 	else
// 		return (NULL);
		
	
	
			
	// while (!buff)
	// {	
	// 	current = buff[i]; 
	// 	if (buff != '\0' && current == '\n')
	// 		{
	// 			save = buff + i;
	// 			i++;
	// 		}
	// 	else
	// 		i++;
	// save = (char *)malloc(sizeof(char) * (size + 1));
	// if(!save) // failed malloc() , !save == !size
	// 	return (NULL);
		
	// 	if(buff != 0 && strchr(buff, '\n'))
	//  	{
	// 		save = buff
	// 	}
	// }
	//save[i] = '\0';
	
	// i = 0;
	// while(i < size)
	// {
	// 	if(buff != 0 && strchr(buff, '\n'))
	// 	{
	// 		//save = buff[i];
	// 		printf("found \n");
	// 		printf("contents: %s", buff);
	// 		//printf("%s", buff[]);
			
	// 	}
	// // 	return (&save);
	// 	i++;
	// }
	
// 	return ("hello");
// 	close(fd);
// 	free(save);
	
// }

char *ft_one_line(char *save) //read one line each in save file(saved whole txt) 
{	
	int len;
	int i;
	char *str;
	
	i = 0;
	if(!save)
		return (NULL);
	len = ft_strlen(save);
	while(save[i] != '\0' && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (len - i + 1));
	i++;
	if(!str)
		return (NULL);
	str[i] = '\0';
	
	return(str);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *new_s;
	int i;
	int j;

	i = 0;
	j = 0;
	if(!s1)
		s1 = "";
	new_s =(char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if(!new_s)
	{
		free(new_s);
		return (NULL);
	}		
	while(*s1)
	{
		new_s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new_s[j] = s2[i];
		i++;
		j++;
	}
	new_s[j] = '\0';
	return (new_s);
}

char	*ft_read(int fd, char *save) // read file(BUFFER_SIZE) and save in static char* save
{
	int read_return;
	char *buff;
	
	read_return = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buff)
		return(NULL);
	while(read_return > 0)
	{
		read_return = read(fd, buff, BUFFER_SIZE);
		if(read_return == -1)
			return (NULL);
		buff[read_return] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return(save);
	
}
char	*get_next_line(int fd)// last function(return one line)
{
	static char* save;
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!save)
		return(NULL);
	save = ft_read(fd, save);
	if(*save)
	{
		line = ft_one_line(save);
		
	}
	free(save);
	return(line);
}


	
	



int main(void)
{
    int fd = open("test.txt", O_RDONLY);
	int i;

    if (fd == -1)
    {
        perror("파일 열기 실패");
        return 1;
    }
	
   
    while (i > 7)
    {
        // 한 줄을 처리 (예: 출력)
        printf("라인: %s\n", get_next_line(fd));
    }

    close(fd);
    return 0;
}
	// while (( size = read(fd, buff, 5)) != 0) // read 5bytes each and write (no, size = ~ seperatly once)
	// {
	// 	if (size == -1) // 0: successful completion/ >0 end-of-file or Error
	// 	{
	// 		return (0);
	// 	}
	// 	write(1, buff, size);
	// }
	// size =  read(fd, buff, 100); // read (n)bytes and save in buff
	// printf("size : %d\n", size);
	// if(fd > 0 && strchr(buff, '\n'))
	// 	{
	// 		save = strchr(buff, '\n');
	// 		printf("found \n");
	// 		printf("contents: %s", buff);
	// 		printf("%s", save );
	// 	}
	// //write(1, buff, size);	
	// close(fd);
// 	return 0;
// }

/*
get_next_line()
-  check fd. check string
- read file(function )
(open file), read file read(int fd, void *buff, size_t byte)


if ft_strchr(string, /n) : save in the static char *  variable? (save and save and save...)
4. 
read, malloc, free
ssize_t read(int fildes, void *buf, size_t nbyte);

*/