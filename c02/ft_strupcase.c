/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:46:36 by lberthal          #+#    #+#             */
/*   Updated: 2023/08/31 18:40:57 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strupcase(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 97 && str[i] <= 122))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
/*
int main(void)
{
	char	str[] = "guv4hg";
	ft_strupcase(str);
	printf("str is alpha : %s\n", str);
}
*/
