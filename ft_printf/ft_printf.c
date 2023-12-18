/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:29 by lucas             #+#    #+#             */
/*   Updated: 2023/12/18 11:48:25 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		return (hexa_bases(args, &c));
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
	// char c;
	// char *s;
	// long int i;
	// int y;
	// unsigned int z;
	// char *s;

	// c = 'v';
	// s = "des strings aussi";
	// i = 4583820120;
	// y = -5847569;
	// z = 42;
	// s = NULL;
	ft_printf("%p", 12);
	return (0);
}