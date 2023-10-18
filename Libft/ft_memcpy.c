/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:09:56 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/18 21:24:51 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((const unsigned char*)src)[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
// 	unsigned char dest[] = "hello world";
// 	unsigned char dest1[] = "hello world";
// 	const unsigned char src[] = "tests";
// 	const unsigned char src1[] = "tests";

// 	printf("%s\n", (unsigned char*)ft_memcpy(dest, src, 5));
// 	printf("%s\n", (unsigned char*)memcpy(dest1, src1, 5));
// }