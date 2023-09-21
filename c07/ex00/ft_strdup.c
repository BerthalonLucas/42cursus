/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:24:27 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/19 17:00:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char *ft_strdup(char *src)
{
	char *str;
	int len;
	int i;

	i = 0;
	len = ft_strlen(src);
	str = malloc(sizeof(*src) * len);
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

int main(void)
{
	char src[] = "dur la vie";

	printf("%s\n", ft_strdup(src));
	free(ft_strdup(src));
}