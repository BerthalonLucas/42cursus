/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:46:36 by lberthal          #+#    #+#             */
/*   Updated: 2023/08/31 18:58:50 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strlowcase(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 65 && str[i] <= 90))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
/*
int main(void)
{
	char	str[] = "NODVEMFL74V JK";
	ft_strlowcase(str);
	printf("str is alpha : %s\n", str);
}
*/
