/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:18:36 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/09 00:00:32 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	while (i < nb && src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "SOURCE";
	char	dest1[50] = "DESTINATION";
	char	dest2[50] = "DESTINATION";
	unsigned int	nb;

    nb = 20;
    printf("%s\n", ft_strncat(dest1, src, nb));
    printf("%s\n", strncat(dest2, src, nb));
}