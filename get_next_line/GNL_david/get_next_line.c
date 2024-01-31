/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daribeir < daribeir@42mulhouse.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:22:38 by daribeir          #+#    #+#             */
/*   Updated: 2023/10/22 17:02:49 by daribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*stack = NULL;

	init_args(&a, fd, &stack);
	if (a.rid == -1 || !read_to_stack(&a))
	{	
		free(stack);
		stack = NULL;
		return (free(a.buffer), NULL);
	}
	if (a.nlptr)
		a.line = ft_substr(stack, 0, a.nlptr - (*a.stack) + 1);
	if (a.nlptr)
		flush_stack(&a);
	else
	{
		a.line = ft_substr(stack, 0, a.stack_len);
		free(stack);
		stack = NULL;
	}
	if (ft_strlen(a.line) == 0)
		return (free(a.line), NULL);
	return (a.line);
}
