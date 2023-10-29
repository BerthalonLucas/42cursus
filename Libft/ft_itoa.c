/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:00:28 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/28 01:05:30 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_count(int n)
{
	int i;
	
	i = 0;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int n)
{
	char *str;
	int i;
	int neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	if (n < 0)
		neg = 1;
	if (n < 0)
		n *= -1;
	str = malloc(sizeof(char *) * (ft_count(n) + neg) + 1);
	if (!str)
		return (NULL);
	i = ft_count(n) + neg;
	str[i] = '\0';
	while (i)
	{
		i--;
		str[i] = n % 10 + '0';
		n /= 10;
	}
	if (neg  == 1 && i == 0)
		str[i] = '-';
	return (str);
}

int main(void)
{	
	printf("%s\n", ft_itoa(-1));
	printf("%s\n", ft_itoa(123456789));
	printf("%s\n", ft_itoa(-123456789));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}