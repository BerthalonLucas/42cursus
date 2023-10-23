/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:05:28 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/22 23:31:27 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

// int main(void)
// {
// 	char *str = "";
// 	char *str1 = "";
// 	char *rep = ft_strdup(str);
// 	char *rep1 = strdup(str1);
	
// 	printf("%s\n", ft_strdup(rep));
// 	printf("%s\n", strdup(rep1));
// 	free(rep);
// 	free(rep1);
// 	return (0);
// }