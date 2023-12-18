/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:53:10 by lucas             #+#    #+#             */
/*   Updated: 2023/12/18 20:00:59 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	character(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	hexa_lower(unsigned long long i, char *base)
{
	if (i >= 16)
		P_hexa_lower(i / 16, base);
	write(1, &base[i % 16], 1);
	return (count_hex(i));
}

int	hexa_upper(unsigned long long i, char *base)
{
	if (i >= 16)
		P_hexa_upper(i / 16, base);
	write(1, &base[i % 16], 1);
	return (count_hex(i));
}

int	pointer(unsigned long long i, char *base)
{
	if (i >= 16)
		P_pointer(i / 16, base);
	write(1, &base[i % 16], 1);
	return (count_hex(i));
}

int	hexa_bases(va_list args, char c)
{
	unsigned long long	n;

	if (c == 'x')
	{
		n = va_arg(args, unsigned int);
		return (P_hexa_lower(n, "0123456789abcdef"));
	}
	if (c == 'X')
	{
		n = va_arg(args, unsigned int);
		return (P_hexa_upper(n, "0123456789ABCDEF"));
	}
	if (c == 'p')
	{
		n = va_arg(args, unsigned long long);
		if ((void *)n == NULL)
		{
			write(1, "(nil)", 5);
			return (5);
		}
		write(1, "0x", 2);
		return (2 + P_pointer(n, "0123456789abcdef"));
	}
	return (0);
}
