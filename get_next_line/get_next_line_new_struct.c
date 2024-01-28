/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new_struct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:39:31 by lberthal          #+#    #+#             */
/*   Updated: 2024/01/28 09:44:21 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_struct.h"

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
	while (str && str[i])
		i++ ;
	return (i);
}

int    ft_find_slash(t_gnl *g)
{
	int	i;

	i = 0;
	while (*(g->buffer_ptr) && *(g->buffer_ptr)[i])
	{
		if (*(g->buffer_ptr)[i] == '\n')
			return (g->n_ptr = *(g->buffer_ptr) + i, 1);
		i++;
	}
	if (*(g->buffer_ptr) && *(g->buffer_ptr)[i] == '\n')
		return (g->n_ptr = *(g->buffer_ptr) + i, 1);
	return (g->n_ptr = *(g->buffer_ptr) + i, 0);
}

int	ft_stockstr(t_gnl *g)
{
	char *str;
	int len;
	int i;

	i = 0;
	len = ft_strlen(*(g->buffer_ptr)) + ft_strlen(g->str_stock) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (-1);
	if (g->str_stock[i] != '\0')
	{
		while (g->str_stock[i] != '\0')
		{
			str[i] = g->str_stock[i];
			i++;
		}
	}
	ft_find_slash(g);
	while (*(g->buffer_ptr) != (g->n_ptr))
	{
		str[i] = *(*g->buffer_ptr);
		i++;
		(*g->buffer_ptr)++;
	}
	g->str_stock = str;
	return (0);
}

int	reader(t_gnl *g)
{
	int rid;

	// printf("%d\n", g->fd);
	g->str_stock = "\0";
	read(g->fd, (*g->buffer_ptr), BUFFER_SIZE);
	ft_stockstr(g);
	while (ft_find_slash(g))
	{
		rid = read(g->fd, *(g->buffer_ptr), BUFFER_SIZE);
		ft_stockstr(g);
	}
	// g->n_ptr = ft_find_slash(g);
	ft_memmove(*(g->buffer_ptr), g->n_ptr + 1, ft_strlen(*(g->buffer_ptr)) - (g->n_ptr - *(g->buffer_ptr)));
	return (rid);
}

static void init_struct(t_gnl *g, int fd, char **buffer)
{
	g->fd = fd;
	g->end = BUFFER_SIZE;
	g->str_stock = NULL;
	g->buffer_ptr = buffer;
	g->n_ptr = NULL;
}
char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	t_gnl g;
	
	// printf("%d\n", fd);
	init_struct(&g, fd, (char **) &buffer);
	if (buffer[0] == '\0')
	{
		if (reader(&g) < 0)
			return (NULL);
		else
			return (g.str_stock);
	}
	return (g.str_stock);
}
int main(void)
{
	int fd = open("to_read.txt", O_RDONLY);
	int i;
	char *line;

	i = 0;
	while (i < 5)
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