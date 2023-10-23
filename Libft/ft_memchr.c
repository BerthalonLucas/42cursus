/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:59:02 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/20 17:57:03 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char*)s)[i] == (unsigned char)c)
			return ((unsigned char*)s + i);
		else
			i++;
	}
	return (NULL);
}

// int main(void)
// {

// 	printf("%s\n", (char*)ft_memchr("test juste pour voir", 'j', 11));
// 	printf("%s\n", (char*)memchr("test juste pour voir", 'j', 11));
// }