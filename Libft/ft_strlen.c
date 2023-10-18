/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:03:10 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/18 20:32:00 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

// int main(void)
// {
// 	char str[] = "Hello World!";
// 	printf("%ld\n", ft_strlen(str));
// 	printf("%ld\n", strlen(str));
// 	return (0);
// }