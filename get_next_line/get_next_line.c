/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:44:15 by lucas             #+#    #+#             */
/*   Updated: 2023/11/23 14:34:52 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}


char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && i < ft_strlen(s))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size - 1 && size != 0)
	{
		dst[i] = src[i];
		++i;
	}
	if (size)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char *ft_first_line(char *buff, char *stock)
{
	char *line;
	size_t	len;
	
	if (!buff)
		return (NULL);
	line = buff;
	len = ft_strlen(line);
	while (*line != '\n')
		line++;
	line++;
	stock = ft_strdup(line);
	len = ft_strlen(buff) - ft_strlen(line);
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buff, len);
	printf("%s\n", stock);
	return (line);
}
char *ft_next_line(char *buff,char *stock)
{
	
}

char *get_next_line(int fd)
{
	static char *str_stock;
	char buffer[60];

	str_stock = "\0";
	read(fd, buffer, 60);
	return (ft_first_line(buffer, str_stock));
}

int main(void)
{
	int fd = open("to_read.txt", O_RDONLY);
	//char *buffer = "ta mere en slip\nelle fait des galipettes";
	
	printf("%s\n", get_next_line(fd));
	close(fd);
}




// main test fonction read
// int main(void)
// {
// 	int fd = open("to_read.txt", O_RDONLY);
// 	char buf[20];
// 	size_t count;

// 	count = 19;
// 	ssize_t test_read = read(fd, buf, count);
// 	printf("%d\n", fd);
// 	printf("%s\n", buf);
// 	printf("%ld\n", test_read);
// 	close(fd);
// 	return (0);
// }