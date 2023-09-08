/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:40:03 by arlee             #+#    #+#             */
/*   Updated: 2023/09/08 21:20:33 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// char *get_next_line(int fd)
// {
		
// }
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
# define BUFFER_SIZE 32

int main(void)
{
	int fd;
	int	size;
	char buff[5];
	char *save;

	if ((fd = open("test.txt", O_RDONLY)) == -1)
	{
		return (0);
	}
	
	
	
	while (( size = read(fd, buff, 5)) != 0) // read 5bytes each and write (no, size = ~ seperatly once)
	{
		if (size == -1)
		{
			return (0);
		}
		write(1, buff, size);
	}
	close(fd);
}

/*
1. check fd. check string
2. (open file), read file read(int fd, void *buff, size_t byte)
3. if ft_strchr(string, /n) : save in the static char *  variable?
4. 

read, malloc, free
ssize_t read(int fildes, void *buf, size_t nbyte);
*/