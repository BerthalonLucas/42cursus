/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:29 by lucas             #+#    #+#             */
/*   Updated: 2023/12/18 12:13:34 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>


int selection(char c, va_list args)
{
	if (c == 'c')
		return (P_char(args));
	if (c == 's')
		return (P_string(args));
	if (c == 'd')
		return (P_decimale(args));
	if (c == 'i')
		return (P_interger(args));
	if (c == 'u')
		return (P_unsinged_decimale(args));
	if (c == 'p' || c == 'x' || c == 'X')
		return (hexa_bases(args, c));
	if (c == '%')
	{
		write (1, "%",1);
		return (1);
	}
	return (0);
}

int    ft_printf(const char *s, ...)
{
	va_list args;
	int i;
	
	va_start (args, s);
	i = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s += 2;
			i += selection(*(s - 1), args);
			if (*s == '\0')
				break;
		}
		write(1, *&s, 1);
		i++;
		s++;
	}
	va_end(args);
	return (i);
}

int main(void)
{
	// ft_printf("myp6: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	// printf("pfp6: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	// ft_printf("myp8: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	// printf("pfp8: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("%d\n", ft_printf("myp6: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX));
	printf("%d\n", printf("pfp6: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX));
	printf("%d\n", ft_printf("myp8: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX));
	printf("%d\n", printf("pfp8: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX));
	return (0);
}