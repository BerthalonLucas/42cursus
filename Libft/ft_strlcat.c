/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:22:15 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/18 17:25:40 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	r;

	while (src[size])
		size++;
	i = 0;
	while (dest[i])
	{
		if (dest[i] == '\0')
			dest[i] = *src;
	i++;
	}
	r = size + i;
	size = 1;
	while (i <= r)
	{
		dest[i] = src[size];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int main(void)
{
	char dest[] = "test";
	const char src[] = "plus1";
	
	printf("%d\n", ft_strlcat(dest, src, 0));
	printf("%d\n", strlcat(dest, src, 0));
}