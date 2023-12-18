/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:53:13 by lucas             #+#    #+#             */
/*   Updated: 2023/12/18 11:41:59 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int P_string(va_list args)
{
	char *s;
	int i;
	
	s = va_arg(args, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (*s)
	{
		write(1, *&s, 1);
		s++;
		i++;
	}
	return (i);
}

int P_decimale(va_list args)
{
	long int i;

	i = va_arg(args, long int);
	putnbr((long int)i);
	return (count((long int)i));
}
int P_interger(va_list args)
{
	int i;

	i = va_arg(args, int);
	putnbr((long int)i);
	return (count((long int)i));
}

int P_unsinged_decimale(va_list args)
{
	unsigned int i;

	i = va_arg(args, unsigned int);
	putnbr((long int)i);
	return (count((long int)i));
}

int putnbr(long int i)
{
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i >= 10)
		putnbr(i / 10);
	i = i % 10 + '0';
	write(1, &i, 1);
	return (0);
}