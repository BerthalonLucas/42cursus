/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:44:15 by lucas             #+#    #+#             */
/*   Updated: 2023/11/20 14:34:30 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int fd = open("to_read.txt", O_RDONLY);
	char buf[100];
	size_t count;

	count = 19;
	ssize_t test_read = read(fd, buf, count);
	printf("%d\n", fd);
	printf("%s\n", buf);
	printf("%ld\n", test_read);
	close(fd);
	return (0);
}