/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:49:46 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/23 02:14:01 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;
	
	i = ft_strlen(s) - 1;
	if (*s == '\0')
		return ((char*)s + ft_strlen(s));
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		i--;
	}
	if (*((char*)s + i) == (char)c)
		return ((char*)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strrchr("teste", 'e'));
// 	printf("%s\n", strrchr("teste", 'e'));
// }