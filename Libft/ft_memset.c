/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:27:02 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/22 23:59:58 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)s)[i] = c;
		i++;
	}
	return (s);
}
// int main(void)
// {
// 	unsigned char str[] = "je m'en fou de ta life";
// 	unsigned char str2[] = "je m'en fou de ta life";
// 	printf("%s\n", str);
// 	printf("after ft_memeset : %s\n", (char*)ft_memset(str, 120, 9));
// 	printf("after memset : %s\n", (char*)memset(str2, 120, 5));
// }