/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:53:10 by lucas             #+#    #+#             */
/*   Updated: 2023/12/18 12:02:36 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int P_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}
int P_hexa_lower(unsigned long long i, char *base)
{
	if (i >= 16)
		P_hexa_lower(i / 16, base);
	write(1, &base[i % 16], 1);
	return (count_hex(i));
}
int P_hexa_upper(unsigned long long i, char *base)
{
	if (i >= 16)
		P_hexa_upper(i / 16, base);
	write(1, &base[i % 16], 1);
	return (count_hex(i));
}
int P_pointer(unsigned long long i, char *base)
{
	if (i >= 16)
		P_pointer(i / 16, base);
	write(1, &base[i % 16], 1);
	return (count_hex(i));
}

int hexa_bases(va_list args, char c)
{
	char *base;
	unsigned long long n;
	n = va_arg(args, unsigned long long);
	if (c == 'x')
	{
		base = "0123456789abcdef";
		return (P_hexa_lower(n ,base));
	}
	if (c == 'X')
	{
		base = "0123456789ABCDEF";
		return (P_hexa_upper(n, base));
	}
	if (c == 'p')
	{
		write(1, "0x", 2);
		base = "0123456789abcdef";
		return (2 + P_pointer(n ,base));
	}
	return (0);
}
