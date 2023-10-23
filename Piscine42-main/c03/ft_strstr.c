/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:41:23 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/06 22:17:21 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strlen(char *to_find);

int ft_same(char *str,char *to_find, int j, int k)
{
	while (str[k] == to_find[j] && str[k] && to_find[j])
	{
		k++;
		j++;
	}
	if (j != ft_strlen(to_find))
		return (0);
	else
		return (1);
}

int ft_strlen(char *to_find)
{
	int i;

	i = 0;
	while (to_find[i])
	{
		i++;
	}
	return (i);
}

char *ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int k;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	else
	{
		while (str[i])
		{
			j = 0;
			k = i;
			if (str[i] == to_find[j])
			{
				if (ft_same(str, to_find, j, k) == 1)
				return (&str[i]);
			}
			i++;
		}
		return (0);
	}
}
/*
int	main(void)
{
	char	str[] = "vas me chercher ton slip et met la table";
	char	to_find[] = "slip";

	printf("ma fonction = %s\n", ft_strstr(str, to_find));
	printf("fonction de base = %s\n",  strstr(str, to_find));
}*/
