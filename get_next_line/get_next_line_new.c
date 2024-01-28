/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:39:31 by lberthal          #+#    #+#             */
/*   Updated: 2024/01/28 09:41:02 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

char    *ft_strchr(char *s, int c)
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

char	*ft_stockstr(char *start, int end, char *str_stock)
{
	char *str;
	int len;
	int i;

	i = 0;
	len = ft_strlen(start) + ft_strlen(str_stock) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	if (*str_stock != '\0')
		{
			while (str_stock[i] != '\0')
				{
					str[i] = str_stock[i];
					i++;
				}
		}
	while (*start != ft_strchr)
	{
		str[i] = *start;
		i++;
		start++;
	}
	str_stock = str;
	return (str_stock);
}

char	*reader(char *buffer, int fd)
{
	char *str_stock;

	str_stock = "\0";
	while (!ft_strchr(buffer, '\n'))
	{
		read(fd, buffer, BUFFER_SIZE);
		str_stock = ft_stockstr(buffer, BUFFER_SIZE, str_stock);
	}
	// printf("%s\n", buffer);
	return (str_stock);
}
char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];

	if (buffer[0] == '\0')
	{
		return (reader(buffer, fd));
	}
	return (reader(buffer, fd));
}
int main(void)
{
	int fd = open("to_read.txt", O_RDONLY);
	//char *buffer = "ta mere en slip\nelle fait des galipettes";
	
	printf("%s\n", get_next_line(fd));
	close(fd);
}




// // main test fonction read
// int main(void)
// {
// 	int fd = open("to_read.txt", O_RDONLY);
// 	char buf[2];
// 	size_t count;

// 	count = 1;
// 	ssize_t test_read = read(fd, buf, count);
// 	printf("%d\n", fd);
// 	printf("%s\n", buf);
// 	printf("%ld\n", test_read);
// 	close(fd);
// 	return (0);
// }