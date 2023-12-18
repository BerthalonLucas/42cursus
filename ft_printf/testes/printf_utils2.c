/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:53:10 by lucas             #+#    #+#             */
/*   Updated: 2023/12/03 19:49:17 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int P_unsinged_decimale(unsigned int)
{
	
}
int P_hexa_lower(unsigned long long i, char *base)
{
	int n;

	n = 0;
	if (n < 16)
	{
		P_hexa_lower(i / 16, base);
		n = i % 16;
		write(1, &n, 1);
	}
	
}
int P_hexa_upper(unsigned long long i, char *base)
{
	int n;

	n = 0;
	if (n < 16)
	{
		P_hexa_lower(i / 16, base);
		n = i % 16 + base;
		write(1, &n, 1);
	}
}
int P_percent(char c);

char *hexa_bases(va_list args, const char *s)
{
	char *base;
	unsigned long long n;

	n = va_arg(args, unsigned long long);
	if (*s == 'x')
	{
		base = "0123456789abcdef";
		P_hexa_lower(n ,base);
	}
	if (*s == 'X')
	{
		base = "0123456789ABCDEF";
		P_hexa_upper(n, base);
	}
}