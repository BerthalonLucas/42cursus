/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:39:31 by lberthal          #+#    #+#             */
/*   Updated: 2024/02/01 03:19:20 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	lens = ft_strlen(g->str_stock) + BUFFER_SIZE + 1;
	str = malloc(sizeof(char) * lens);
	if (!str)
	{
		free(str);
		return (-1);
	}
	ft_strlcpy(str, g->str_stock, lens);
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
	ft_strjoin(g, buffer);
	while (!ft_find_slash(g, buffer))
	{
		g->rid = read(g->fd, buffer, BUFFER_SIZE);
		if (g->rid >= 0)
			buffer[g->rid] = '\0';
		if (g->rid <= 0 && *g->str_stock == '\0')
			return (ft_bzero(buffer), buffer = NULL, -1);
		else if (g->rid == 0)
			return (ft_bzero(buffer), 0);
		ft_strjoin(g, buffer);
	}
	ft_memmove(buffer, g->n_ptr + 1, BUFFER_SIZE - (g->n_ptr - buffer));
	return (g->rid);
}

char *get_next_line(int fd)
{
	static char buffer[1024][BUFFER_SIZE + 1];
	t_gnl g;
	
	if (fd < 0)
		return (NULL);
	buffer[fd][BUFFER_SIZE] = '\0';
	g.fd = fd;
	g.str_stock = NULL;
	g.n_ptr = NULL;
	g.rid = read(g.fd, g.str_stock, 0);
	if (g.rid < 0)
		return (ft_bzero(buffer[fd]), NULL);
	if (buffer[fd][0] == '\0')
	{
		if (reader(&g, buffer[fd]) < 0)
			return (free(g.str_stock), NULL);
	}
	else if (reader(&g, buffer[fd]) < 0)
		return (free(g.str_stock), NULL);
	return (g.str_stock);
}
// int main(void)
// {
// 	int fd = open("to_read.txt", O_RDONLY);
// 	int i;
// 	char *line;

// 	i = 0;
// 	while (i < 2)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	// free(line);
// 	// printf("%s\n", get_next_line(fd));
// 	close(fd);
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
// int main(void)
// {
// 		char *name = "to_read.txt";
// 		char *other = "other.txt";
// 		char *line1;
// 		char *line2;
// 		int fd = open(name, O_RDONLY);
// 		int fd2 = open(other, O_RDONLY);
// 		printf("output needed \n---------------------\naaaaaaaaaa\n\nlundi\n\nbbbbbbbbbb\n\nmardi\n\nNULL\n\nmercredi\n\naaaaaaaaaa\n\n");
// 		printf("jeudi\n\nbbbbbbbbbb\n\nccccccccc\n\nvendredi\n\nNULL\n\ndddddddddd\n\nNULL\n\n---------------------\nMY OUTPUT\n----------------------------\n");
// 		/* 1 */ line1 = get_next_line(fd);
// 		printf("%s\n", line1);
// 		free(line1);
// 		/* 2 */ line2 = get_next_line(fd2);
// 		printf("%s\n", line2);
// 		free(line2);
// 		/* 3 */ line1 = get_next_line(fd);
// 		printf("%s\n", line1);
// 		free(line1);
// 		/* 4 */ line2 = get_next_line(fd2);
// 		printf("%s\n", line2);
// 		free(line2);
// 		/* 5 */ line1 = get_next_line(fd);
// 		if (line1 == NULL)
// 			printf("NULL\n");
// 		free(line1);
// 		close(fd);
// 		/* 6 */ line2 = get_next_line(fd2);
// 		printf("%s\n", line2);
// 		free(line2);
// 		fd = open(name, O_RDONLY);
// 		/* 7 */ line1 = get_next_line(fd);
// 		printf("%s\n", line1);
// 		free(line1);
// 		/* 8 */ line2 = get_next_line(fd2);
// 		printf("%s\n", line2);
// 		free(line2);
// 		/* 9 */ line1 = get_next_line(fd);
// 		printf("%s\n", line1);
// 		free(line1);
// 		/* 10 */ line1 = get_next_line(fd);
// 		printf("%s\n", line1);
// 		free(line1);
// 		/* 11 */ line2 = get_next_line(fd2);
// 		printf("%s\n", line2);
// 		free(line2);
// 		/* 12 */ line2 = get_next_line(fd2);
// 		if (line2 == NULL)
// 			printf("NULL\n");
// 		free(line2);
// 		/* 13 */ line1 = get_next_line(fd);
// 		printf("%s\n", line1);
// 		free(line1);
// 		/* 14 */ line1 = get_next_line(fd);
// 		if (line1 == NULL)
// 			printf("NULL\n");
// 		free(line1);
// 	}




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