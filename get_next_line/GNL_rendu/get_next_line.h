/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:44:19 by lucas             #+#    #+#             */
/*   Updated: 2024/02/02 01:13:28 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl
{
	int			fd;
	int			rid;
	char		*str_stock;
	char		*n_ptr;
}	t_gnl;

char	*get_next_line(int fd);
void	ft_bzero(char *buffer);
int		ft_strlen(char *str);
char	*ft_memmove(char *dest, char *src, size_t n);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size, t_gnl *g);
int		ft_find_slash(t_gnl *g, char *buffer);
int		ft_strjoin(t_gnl *g, char *buffer);
int		reader(t_gnl *g, char *buffer);

#endif