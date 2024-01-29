/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:39:31 by lberthal          #+#    #+#             */
/*   Updated: 2024/01/29 20:26:27 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((!dest && !src) || !n)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if ((!dest && !src) || !n)
		return (dest);
	if (dest > src)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str || str[i] == '\0')
		return (0);
	while (str[i])
		i++ ;
	return (i);
}
size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size - 1 && size != 0 && src[i] != '\n')
	{
		dst[i] = src[i];
		++i;
	}
	if (size)
		dst[i] = '\0';
	return (ft_strlen(src));
}
size_t	ft_strlcat(char *dest, char *src, size_t size, t_gnl *g)
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
	while (src[r] && (&src[r - 1] != g->n_ptr))
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

int    ft_find_slash(t_gnl *g, char *buffer)
{
	int	i;

	i = 0;
	while (*buffer && buffer[i])
	{
		if (buffer[i] == '\n')
			return (g->n_ptr = buffer + i, 1);
		i++;
	}
	if (buffer[i] == '\n')
		return (g->n_ptr = buffer + i, 1);
	return (0);
}
// void	clear(char *str)
// {
// 	free(str);
// 	while (*str != '\0')
// 	{
// 		*str = '\0';
// 		str++;
// 	}
// }

// int	ft_stockstr(t_gnl *g, char *buffer)
// {
// 	char *str;
// 	int len;
// 	int i;

// 	i = 0;
// 	len = BUFFER_SIZE + ft_strlen(g->str_stock) + 1;
// 	str = malloc(sizeof(char) * len);
// 	if (!str)
// 		return (-1);
// 	if (g->str_stock && g->str_stock[i] != '\0')
// 	{
// 		while (g->str_stock[i] != '\0')
// 		{
// 			str[i] = g->str_stock[i];
// 			i++;
// 		}
// 	}
// 	if (!g->str_stock)
// 	{
		
// 		if (*g->str_stock != '\0')
// 			clear(g->str_stock);
// 	}
// 	ft_find_slash(g, buffer);
// 	while (*buffer != *(g->n_ptr))
// 	{
// 		str[i] = *buffer;
// 		i++;
// 		buffer++;
// 	}
// 	if (*(g->n_ptr) == '\n')
// 		str[i] = '\n';
// 	g->str_stock = str;
// 	return (0);
// }

int	ft_strjoin(t_gnl *g,char *buffer)
{
	int		lens;
	char	*str;

	if (!g->str_stock || !buffer)
		return (-1);
	lens = ft_strlen(g->str_stock) + BUFFER_SIZE + 1;
	str = malloc(sizeof(char) * lens);
	if (!str)
		return (-1);
	printf("%s\n", "MALLOC");
	ft_strlcpy(str, g->str_stock, lens);
	free(g->str_stock);
	ft_find_slash(g, buffer);
	ft_strlcat(str, buffer, lens, g);
	g->str_stock = str;
	return (0);
}
int	reader(t_gnl *g, char *buffer)
{
	int rid;
	if (!g->str_stock)
	{
		g->str_stock = malloc(sizeof(char) * 1);
		g->str_stock[0] = '\0';
	}
	if (!g->str_stock)
		return(-1);
	
	if (buffer[0] == '\0')
		read(g->fd, buffer, BUFFER_SIZE);
	ft_strjoin(g, buffer);
	while (!ft_find_slash(g, buffer))
	{
		rid = read(g->fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (rid == 0)
			return (-1);
		ft_strjoin(g, buffer);
	}
	// g->n_ptr = ft_find_slash(g);
	ft_memmove(buffer, g->n_ptr + 1, BUFFER_SIZE - (g->n_ptr - buffer));
	return (rid);
}

static void init_struct(t_gnl *g, int fd)
{
	g->fd = fd;
	g->end = BUFFER_SIZE;
	g->str_stock = NULL;
	g->n_ptr = NULL;
}
char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	t_gnl g;
	
	// printf("%d\n", fd);
	if (!fd)
		return (NULL);
	init_struct(&g, fd);
	if (buffer[0] == '\0')
	{
		if (reader(&g, buffer) < 0)
			return (NULL);
		else
			return (g.str_stock);
	}
	if (reader(&g, buffer) < 0)
			return (NULL);
		else
			return (g.str_stock);
	return (g.str_stock);
}
int main(void)
{
	int fd = open("to_read.txt", O_RDONLY);
	int i;
	char *line;

	i = 0;
	while (i < 8)
	{
		line = get_next_line(fd);
		printf("%s", line);
		// free(line);
		i++;
	}
	// printf("%s\n", get_next_line(fd));
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