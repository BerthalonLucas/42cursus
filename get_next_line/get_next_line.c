/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:39:31 by lberthal          #+#    #+#             */
/*   Updated: 2024/02/01 05:53:00 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	return (g->n_ptr = buffer + i, 0);
}

int	ft_strjoin(t_gnl *g,char *buffer)
{
	int		lens;
	char	*str;

	if (!g->str_stock || !buffer)
		return (-1);
	if (g->rid <= ft_strlen(buffer))
		lens = ft_strlen(g->str_stock) + ft_strlen(buffer) + 1;
	else
		lens = ft_strlen(g->str_stock) + g->rid + 1;
	str = malloc(sizeof(char) * lens);
	if (!str)
	{
		free(str);
		return (-1);
	}
	ft_strlcpy(str, g->str_stock, lens);
	if (g->str_stock)
		free(g->str_stock);
	ft_find_slash(g, buffer);
	ft_strlcat(str, buffer, lens, g);
	g->str_stock = str;
	if (g->rid != 0 && g->rid < BUFFER_SIZE)
		buffer[g->rid] = '\0';
	return (0);
}
int	reader(t_gnl *g, char *buffer)
{
	g->str_stock = malloc(sizeof(char) * 1);
	if (!g->str_stock)
		return(-1);
	g->str_stock[0] = '\0';
	if (buffer[0] == '\0')
	{
		g->rid = read(g->fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
	}
	if (ft_strjoin(g, buffer) < 0)
		return (-1);
	while (!ft_find_slash(g, buffer))
	{
		g->rid = read(g->fd, buffer, BUFFER_SIZE);
		if (g->rid < 0)
			return(buffer[0] = '\0', -1);
		if (g->rid <= 0 && *g->str_stock == '\0')
			return (ft_bzero(buffer), buffer = NULL, -1);
		else if (g->rid == 0)
			return (ft_bzero(buffer), 0);
		if (ft_find_slash(g, buffer))
		ft_strjoin(g, buffer);
	}
	ft_memmove(buffer, g->n_ptr + 1, ft_strlen(buffer) - (g->n_ptr - buffer));
	return (g->rid);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	t_gnl g;
	
	if (fd < 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	g.fd = fd;
	g.str_stock = NULL;
	g.rid = read(g.fd, g.str_stock, 0);
	g.n_ptr = NULL;
	if (g.rid < 0)
		return (ft_bzero(buffer), NULL);
	if (buffer[0] == '\0')
	{
		if (reader(&g, buffer) < 0)
			return (free(g.str_stock), NULL);
	}
	else if (reader(&g, buffer) < 0)
		return (free(g.str_stock), NULL);
	return (g.str_stock);
}
// int main(void)
// {
// 	int fd = open("to_read.txt", O_RDONLY);
// 	char *line;
// 	line = (void *) -1;
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	// free(line);
// 	// printf("%s\n", get_next_line(fd));
// 	// close(fd);
// 	// fd = open("error", O_RDONLY);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// printf("\n");
// 	// free(line);
// 	// close(fd);
// 	// fd = open("to_read.txt", O_RDONLY);
// 	// i = 0;
// 	// while (i < 4)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// 	i++;
// 	// }
// 	// close(fd);
// }


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