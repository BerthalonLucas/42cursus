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
	if (len == (size_t)-1)
		len = ft_strlen(big);
	str = (char*)big;
	while (big[i] && i < len)
	{
		while (little[u] == big[i + u] && little[u] != '\0' && (i + u) < len)
			u++;
		if (u != ft_strlen(little))
				u = 0;
		if (u == ft_strlen(little))
			return (str);
		i++;
		str++;
	}
	return (NULL);
}