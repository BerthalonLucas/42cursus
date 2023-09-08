/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:47:02 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/07 00:16:47 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i]) && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	s1[] = "yyyyyhy";
	char	s2[] = "yyyyyy";
	int result;

	result = strcmp(s1, s2);
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", result);
}
*/
