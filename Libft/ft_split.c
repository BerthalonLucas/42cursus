/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:24:42 by lberthal          #+#    #+#             */
/*   Updated: 2023/11/02 18:07:51 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  ft_count(char const *s, char c);

static void ft_free(char **tab, int c_numb)
{
	while (c_numb > 0)
	{
		free(tab[c_numb]);
		printf("free de tab[%d]\n", c_numb);
		c_numb--;
	}
	free(tab);
}

static char	**ft_alloc(char const *s, char c,char **tab, int z)
{
	int y;
	int	i;
	int	c_numb;

	i = 0;
	y = -1;
	c_numb = ft_count(s, c);
	while (*s == c)
		s++;
	while (++y, c_numb > 0)
	{
		if (s[z + y] == c || s[z + y] == '\0')
		{
			tab[i] = ft_substr(s, z, y);
			if (!tab[i])
				return (ft_free(tab, c_numb), NULL);
			c_numb--;
			while (s[z + y] == c)
				++y;
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
	if (!ft_strchr(s, c))
		return (1);
	while (s[i] == c)
		i++;
	if (i == (int)ft_strlen(s))
		return (0);
 	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] == '\0')
				return (limiter);
			if (s[i])
			limiter++;
		}
		i++;
	}
	return (limiter);
}

char **ft_split(char const *s, char c)
{
	int	z;
	char **tab;
	
	z = 0;
	tab = NULL;
	if (!s)
		return (tab);
	if (s[0] == '\0')
	{
		tab = (char **)malloc(sizeof(char *) * 1);
		tab[0] = NULL;
		return (tab);
	}
	tab = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!tab)
		return(NULL);
	if (!ft_strchr(s, c))
	{
		tab[0] = ft_strdup(s);
		tab[1] = NULL;
		return (tab);
	}
	return (ft_alloc(s, c, tab, z));
}

// int main(void)
// {
// 	// int i = 0;
// 	// char *str = "    lyigk iugvuvhj";
// 	// char *str = "123456789";
// 	// char *str = "545  516     651   ";
// 	// char *str = "123  1234   12345  123456";
// 	char c = ' ';
	
// 	while (i < 10)
// 	{
// 		if (ft_split(str, c) == NULL)
// 			return (printf("fonction NULL for STR"));
// 		if (ft_split(str, c)[i] == NULL)
// 		{
// 			printf("String, NULL for STR\n");
// 			return (0);
// 		}
// 		else
// 			printf("%s\n", ft_split(str, c)[i]);
// 		i++;
// 	}
// }