/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:44:19 by lucas             #+#    #+#             */
/*   Updated: 2024/01/29 18:23:00 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif
typedef struct s_gnl
{
	int			fd;
	int			end;
	char        *str_stock;
	char 		*n_ptr;
}	t_gnl;

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> // Pour open
# include <stdio.h> // Pour printf

char *get_next_line(int fd);

#endif