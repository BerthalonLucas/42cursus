/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:39:31 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/08 23:33:30 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	else
	{
		while (s1[i] && s2[i])
		{
			if ((s1[i] != s2[i]) && (i <= n && j <= n))
			{
				return (s1[i] - s2[i]);
			}
			else
			{
				i++;
				j++;
			}
		}
		return (s1[i] - s2[i]);
	}
}

int main(void)
{
	char	s1[] = "michel, forever tonight";
	char	s2[] = "michel, forever tonight?uig";
	unsigned int n;

	printf("string 1 : %d\n", ft_strncmp(s1, s2, 41));
	printf("string 1 : %d\n", strncmp(s1, s2, 41));
}
