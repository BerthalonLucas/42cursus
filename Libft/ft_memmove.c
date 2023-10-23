/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:24:58 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/22 23:36:38 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		while (n--)
			((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

// int main(void)
// {
// 	unsigned char dest[] = "hello world";
// 	unsigned char dest1[] = "hello world";

// 	printf("%s\n", (unsigned char*)ft_memmove(dest + 6, dest, 5));
// 	printf("%s\n", (unsigned char*)memmove(dest1 + 6, dest1, 5));
// }
