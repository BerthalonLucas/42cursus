/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:24:42 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/30 03:07:36 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_count(char const *s, char c);

static void ft_free(char **tab)
{
	
}

static char	**ft_alloc(char const *s, char c, int y, int z)
{
	char **tab;
	int	i;
	int	c_numb;

	i = 0;
	c_numb = ft_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (c_numb + 1));
	if (!tab)
		return(NULL);
	while (++y, c_numb > 0)
	{
		if (s[y] == c || s[y] == '\0')
		{
			tab[i] = ft_substr(s, z, y);
			if (!tab[i])
				return (NULL);
			c_numb--;
			while (s[y] == c)
				y++;
			i++;
			z += y;
			y = 0;
		}
	}
	return (tab[i] = NULL, tab);
}

static int  ft_count(char const *s, char c)
{
	int i;
	int	limiter;

	i = 0;
	limiter = 1;
	if (!s)
		return (-1);
	while (s[i])
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
	int	y;
	int	z;
	
	y = - 1;
	z = 0;
	return (ft_alloc(s, c, y, z));
}

int main(void)
{
	int i = 0;
	char *str = "hello world";
	char c = ' ';
	
	while (i < 3)
	{
		if (ft_split(str, c)[i] == NULL)
			printf("String, NULL\n");
		else
			printf("%s\n", ft_split(str, c)[i]);
		i++;
	}
}