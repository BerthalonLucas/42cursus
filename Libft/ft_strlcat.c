/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:22:15 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/19 18:44:47 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t r;
	size_t src_len;

	i = 0;
	r = 0;
	src_len = ft_strlen(src);
	while (dest[i])
		i++;
	if (i >= size)
		return (src_len + size);
	while (src[r])
	{
		if (i == size - 1)
			break ;
		dest[i] = src[r];
		i++;
		r++;
	}
	dest[i] = '\0';
	return (ft_strlen(src) + (r - 1));
}

int main(void)
{
	char dest[] = "123456789";
	const char src[] = "abcde";
	char dest1[] = "123456789";
	const char src1[] = "abcde";
	
	printf("%ld\n", strlcat(dest1, src1, 12));
	printf("%s\n", dest1);
	printf("%s\n", src1);
	printf("%ld\n", ft_strlcat(dest, src, 12));
	printf("%s\n", dest);
	printf("%s\n", src);
}