/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:24:42 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/29 23:43:09 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_alloc(char **tab,char const *s, char c, int y, int z)
{
	int	i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!tab)
		return(NULL);
	while (s[z + y])
	{
		if (s[y] == c)
		{
			tab[i] = malloc(sizeof(char) * y);
			if (!tab[i])
				return (NULL);
			ft_strlcpy(tab[i], s + z, y);
			while (s[++y] == c)
			i++;
			z = y - 1;
			y = 0;
		}
		y++;
	}
	tab[i] = NULL;
	return (tab);
}

static int  ft_count(char const *s, char c)
{
	int i;
	int	limiter;

	i = 0;
	limiter = 0;
	if (!s)
		return (-1);
	while (s[i] != c)
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			limiter++;
		}
		i++;
	}
	return (limiter);
}

char **ft_split(char const *s, char c)
{
	char	**tab;
	int	y;
	int	z;
	
	y = 0;
	z = 0;
	return (ft_alloc(tab, s, c, y, z));
}

int main(void)
{
	
}