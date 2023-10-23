/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:22:15 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/23 01:22:25 by lberthal         ###   ########.fr       */
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
	size_t	dest_len;

	i = 0;
	r = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
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
	if (size <= (src_len + ft_strlen(dest)))
		return (dest_len + src_len);
	return (ft_strlen(dest));
}
