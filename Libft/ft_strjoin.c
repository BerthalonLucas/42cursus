/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:32:04 by lberthal          #+#    #+#             */
/*   Updated: 2023/11/02 18:09:08 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	int lens;
	char	*str;
	
	if (!s1 || !s2)
		return (NULL);
	lens = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * lens);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, lens);
	ft_strlcat(str, (char *)s2, lens);
	return (str);
}

// int main(void)
// {
// 	char *strt1;
// 	char *strt1b;
// 	char *strt2;
// 	char *strt2b;
// 	char *strt3;
// 	char *strt3b;
	
// 	strt1 = "concate";
// 	strt1b = "nation";
// 	strt2 = "";
// 	strt2b = "";
// 	strt3 = "";
// 	strt3b = "devrait return null";

	
// 	printf("%s\n", ft_strjoin(strt1, strt1b));
// 	printf("%s\n", ft_strjoin(strt2, strt2b));
// 	printf("%s\n", ft_strjoin(strt3, strt3b));
// 	return (0);
// }