/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:18:36 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/08 23:52:20 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	dest[j] = src[i];
	while (src[i] != '\0')
	{
		dest[j] = src[i];
	i++;
	j++;
	}
	dest[j] = '\0';
	return (dest);
}

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	src[] = "";
	char	dest[50] = "";
	char	dest2[50] = "";

	printf("%s\n", ft_strcat(dest, src));
	printf("%s\n", strcat(dest2, src));
}
