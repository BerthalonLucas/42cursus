/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:41:23 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/06 14:23:08 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_count(char *to_find);
int ft_lengh(char	*str,char	*to_find);
int ft_strcmp(char *str, char *to_find, int i);
char *ft_strstr(char *str, char *to_find);

int ft_count(char *to_find)
{
	int cb;

	cb = 0;
	while (to_find[cb])
	{
		cb++;
	}
	return (cb);
}
int ft_lengh(char	*str,char	*to_find)
{
	int c;

	c = 0;
	while (str[c] == to_find[c])
	{
		c++;
	}
	if (ft_count(to_find) == c)
		return (1);
	else
		return (0);
}

int ft_strcmp(char *str, char *to_find, int i)
{
	if (str[i] == to_find[i])
		return (1);
	else
		return (0);
}
char *ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i = 0;
		while (ft_strcmp(str, to_find, i) == 0)
		{
			if (ft_lengh(str, to_find) == 1)
			{
			str = &str[i];
			return(str);
			}
			else
			i++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	str[] = "vas me chercher ton slip et met la table";
	char	to_find[] = "slip";

	printf("ma fonction = %s\n", ft_strstr(str, to_find));
	printf("fonction de base = %s\n",  strstr(str, to_find));
}
