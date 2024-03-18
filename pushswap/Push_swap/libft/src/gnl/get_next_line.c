/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:39:31 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/14 00:25:58 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_find_slash(t_gnl *g, char *buffer)
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

int	ft_strjoin_gnl(t_gnl *g, char *buffer)
{
	int		lens;
	char	*str;

	if (!g->str_stock || !buffer)
		return (-1);
	if (g->rid < ft_strlen_gnl(buffer))
		lens = ft_strlen_gnl(g->str_stock) + ft_strlen_gnl(buffer) + 1;
	else
		lens = ft_strlen_gnl(g->str_stock) + g->rid + 1;
	str = malloc(sizeof(char) * lens);
	if (!str)
	{
		free(str);
		return (-1);
	}
	ft_strlcpy_gnl(str, g->str_stock, lens);
	if (g->str_stock)
		free(g->str_stock);
	ft_find_slash(g, buffer);
	ft_strlcat_gnl(str, buffer, lens, g);
	g->str_stock = str;
	if (g->rid != 0 && g->rid < BUFFER_SIZE)
		buffer[g->rid] = '\0';
	return (0);
}

int	reader(t_gnl *g, char *buffer)
{
	g->str_stock = malloc(sizeof(char) * 1);
	if (!g->str_stock)
		return (-1);
	g->str_stock[0] = '\0';
	if (buffer[0] == '\0')
	{
		g->rid = read(g->fd, buffer, BUFFER_SIZE);
		buffer[g->rid] = '\0';
	}
	if (ft_strjoin_gnl(g, buffer) < 0)
		return (-1);
	while (!ft_find_slash(g, buffer))
	{
		g->rid = read(g->fd, buffer, BUFFER_SIZE);
		buffer[g->rid] = '\0';
		if (g->rid < 0)
			return (buffer[0] = '\0', -1);
		if (g->rid <= 0 && *g->str_stock == '\0')
			return (ft_bzero_gnl(buffer), buffer = NULL, -1);
		else if (g->rid == 0)
			return (ft_bzero_gnl(buffer), 0);
		ft_strjoin_gnl(g, buffer);
	}
	mm_gnl(buffer, g->n_ptr + 1, ft_strlen_gnl(buffer) - (g->n_ptr - buffer));
	return (g->rid);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_gnl		g;

	if (fd < 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	g.fd = fd;
	g.str_stock = NULL;
	g.rid = read(g.fd, g.str_stock, 0);
	g.n_ptr = NULL;
	if (g.rid < 0)
		return (ft_bzero_gnl(buffer), NULL);
	if (buffer[0] == '\0')
	{
		if (reader(&g, buffer) < 0)
			return (free(g.str_stock), NULL);
	}
	else if (reader(&g, buffer) < 0)
		return (free(g.str_stock), NULL);
	return (g.str_stock);
}
