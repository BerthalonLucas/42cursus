/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:59:58 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/22 23:56:34 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	
	size_t i;

	i = 0;
	while (src[i] && i < size - 1 && size != 0)
	{
		dst[i] = src[i];
		++i;
	}
	if (size)
		dst[i] = '\0';
	return (ft_strlen(src));
}

// int main(void)
// {
// 	char str[] = "petit test pour voir";
// 	const char str1[] = "autre se";

// 	printf("%lu\n", ft_strlcpy(str, str1, 4));
// 	printf("%lu\n", strlcpy(str, str1, 4));
	
// }