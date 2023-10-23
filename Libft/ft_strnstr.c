/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:08:02 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/22 23:31:09 by lberthal         ###   ########.fr       */
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
	if (!little)
		return ((char*)big);
	str = (char*)big;
	while (big[i] && i < len)
	{
		while (little[u] == big[i] && little[u] != '\0')
		{
			u++;
			i++;
		}
		if (u != ft_strlen(little))
			u = 0;
		if (u == ft_strlen(little))
			break;
		i++;
		str++;
	}
	if (i < len)
		return (str);
	else
		return (NULL);
	return (NULL);
}

// int	main(void)
// {
// 	// char *ptr = "test dans le tester";
// 	// char *little = "da";
// 	// char *result = strnstr("test dans le tester", "das", 6);
// 	// if (result == NULL)
// 	// 	printf("c'est bien NULL\n");
// 	printf("%s\n", strnstr("test dans le tester", "", 6));
// 	printf("%s\n", ft_strnstr("test dans le tester", "", 6));
// 	// char *result1 = ft_strnstr("test dans le tester", "", 6);
// 	// if (result1 == NULL)
// 	// 	printf("c'est bien NULL\n");
// }