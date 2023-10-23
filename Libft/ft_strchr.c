/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:26:04 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/23 01:49:14 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char*)s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)s + i);
	return (NULL);
}

// int main(void)
// {
// 	printf("%s\n", ft_strchr((const char*)"testducona", 0));
// }