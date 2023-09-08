/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:46:36 by lberthal          #+#    #+#             */
/*   Updated: 2023/08/31 03:26:48 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_str_is_lowercase(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 97 && str[i] <= 122))
			return (0);
		i++;
	}
	return (1);
}
/*
int main(void)
{
	char	str[] = "test";
	printf("str is alpha : %d\n", ft_str_is_lowercase(str));
}
*/
