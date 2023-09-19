/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlee <arlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:59:05 by arlee             #+#    #+#             */
/*   Updated: 2023/09/19 20:17:39 by arlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	
	if(!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s + i);
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_s)
	{
		return (NULL);
	}
	while (s1[i])
		new_s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_s[j++] = s2[i++];
	new_s[j] = '\0';
	return (new_s);
}

char	*ft_strdup(const char *s)
{
	char	*s1;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	while (i < len)
	{
		s1[i] = s[i];
		i++;
	}
	s1[len] = '\0';
	return (s1);
}
