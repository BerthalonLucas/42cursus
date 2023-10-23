/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:43:18 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/06 22:10:54 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (dest[i] == '\0')
		return (dest);
	else
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char	dest[] = "world1";
	char	dest2[] = "world1"
	char	src[] = "Hello";
	unsigned int	n;
//	int	c;
//	c = 0;
	n = 7;
//	count(src, c);
	
	printf("My fonction : %s\n%", ft_strncpy(dest, src, n))
	printf("The fonction : %s\n%", strncpy(dest, src, n))
}*/