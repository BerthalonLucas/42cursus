/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:08:02 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/23 22:13:18 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++ ;
	return (i);
}

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	u;
	char *str;
	
	i = 0;
	u = 0;
	if (!*little) 
		return ((char*)big);
	if (!big)
		return (NULL);
	str = (char*)big;
	while (big[i] && i < len)
	{
		while (little[u] == big[i] && little[u] != '\0' && i < len)
		{
			u++;
			i++;
		}
		if (u != ft_strlen(little))
			u = 0;
		if (u == ft_strlen(little))
			return (str);
		i++;
		str++;
	}
	return (NULL);
}
