/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:44:15 by lucas             #+#    #+#             */
/*   Updated: 2024/01/19 17:49:27 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 2

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}


size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	r;
	size_t	src_len;
	size_t	dest_len;

	i = 0;
	r = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	while (dest[i])
		i++;
	if (i >= size)
		return (src_len + size);
	while (src[r])
	{
		if (i == size - 1)
			break ;
		dest[i] = src[r];
		i++;
		r++;
	}
	dest[i] = '\0';
	if (size <= (src_len + ft_strlen(dest)))
		return (dest_len + src_len);
	return (ft_strlen(dest));
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


char	*ft_strjoin(char *s1, char *s2)
{
	int		lens;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lens = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * lens);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, lens);
	ft_strlcat(str, s2, lens);
	free(s1);
	return (str);
}

char *ft_first_line(char *buffer, char *str_stock, int fd)
{
	int i;

	i = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		str_stock = ft_strjoin(str_stock, buffer);
		read(fd, buffer, BUFFER_SIZE);
	}
	str_stock = ft_strjoin(str_stock, buffer);
	while (buffer[i] != '\n')
	{

	}
	return (str_stock);
}

char *get_next_line(int fd)
{
	char *str_stock;
	static char buffer[BUFFER_SIZE];

	str_stock = malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (!str_stock)
		return (NULL);
	str_stock[BUFFER_SIZE] = '\0';
	read(fd, buffer, BUFFER_SIZE);
	return (ft_first_line(buffer, str_stock, fd));
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