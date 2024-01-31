/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:22:38 by daribeir          #+#    #+#             */
/*   Updated: 2024/01/31 07:37:42 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	init_args(t_args *a, int fd, char **stack)
{
	a->fd = fd;
	a->buffer = NULL;
	a->rid = read(fd, a->buffer, 0);
	a->stack = stack;
	a->stack_len = ft_strlen((*stack));
	a->line = NULL;
	a->nlptr = ft_strchr(a, '\n');
}

static char	*init_empty_string(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}

static void	flush_stack(t_args *a)
{
	char	*tmp;

	tmp = (*a->stack);
	a->stack_len = ft_strlen((*a->stack));
	(*a->stack) = \
		ft_substr((*a->stack), a->nlptr - (*a->stack) + 1, a->stack_len);
	a->stack_len = ft_strlen((*a->stack));
	free(tmp);
}

static int	read_to_stack(t_args *a)
{
	if (!BUFFER_SIZE || BUFFER_SIZE < 1 || a->fd < 0 || read(a->fd, 0, 0) < 0)
		return (0);
	if (!(*a->stack))
		(*a->stack) = init_empty_string();
	a->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if ((!a->buffer) || !(*a->stack))
		return (0);
	a->rid = read(a->fd, a->buffer, BUFFER_SIZE);
	if (a->rid == -1)
		return (0);
	while (a->rid)
	{
		a->buffer[a->rid] = '\0';
		(*a->stack) = ft_strjoin((*a->stack), a->buffer);
		a->stack_len = ft_strlen((*a->stack));
		if (ft_strchr(a, '\n'))
			break ;
		a->rid = read(a->fd, a->buffer, BUFFER_SIZE);
		if (a->rid == -1)
			return (0);
	}
	ft_strchr(a, '\n');
	free(a->buffer);
	return (1);
}

char	*get_next_line(int fd)
{
	t_args		a;
	static char	*stack[1024];

	init_args(&a, fd, &stack[fd]);
	if (a.rid == -1 || !read_to_stack(&a))
	{	
		free(stack[fd]);
		stack[fd] = NULL;
		return (free(a.buffer), NULL);
	}
	if (a.nlptr)
		a.line = ft_substr(stack[fd], 0, a.nlptr - (*a.stack) + 1);
	if (a.nlptr)
		flush_stack(&a);
	else
	{
		a.line = ft_substr(stack[fd], 0, a.stack_len);
		free(stack[fd]);
		stack[fd] = NULL;
	}
	if (ft_strlen(a.line) == 0)
		return (free(a.line), NULL);
	return (a.line);
}

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