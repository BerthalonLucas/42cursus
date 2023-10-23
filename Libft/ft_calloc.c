/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:21:09 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/22 19:04:50 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

// int main(void)
// {
// 	char *str;
// 	char *str1;
	
// 	str1 = calloc(10, sizeof(char));
// 	str = ft_calloc(10, sizeof(char));
// 	printf("%s\n", str);
// 	printf("%s\n", str1);
// 	free(str);
// 	free(str1);
// 	return (0);
// }