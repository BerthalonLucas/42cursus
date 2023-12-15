/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:29 by lucas             #+#    #+#             */
/*   Updated: 2023/12/10 20:20:30 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int selection(const char *s, va_list args)
{
	if (*s == 'c')
		return (P_char(args));
	if (*s == 's')
		return (P_string(args));
	if (*s == 'd')
		return (P_decimale(args));
	if (*s == 'i')
		return (P_interger(args));
	if (*s == 'u')
		return (P_unsinged_decimale(args));
	if (*s == 'p' || *s == 'x' || *s == 'X')
		return (hexa_bases(args, s));
	if (*s == '%')
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
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			i = selection(s, args);
			s++;
		}
		write(1, *&s, 1);
		s++;
	}
	va_end(args);
	return (i);
}

// int main(void)
// {
// 	// char c;
// 	// char *s;
// 	// long int i;
// 	// int y;
// 	// unsigned int z;
// 	char *s;

// 	// c = 'v';
// 	// s = "des strings aussi";
// 	// i = 4583820120;
// 	// y = -5847569;
// 	// z = 42;
// 	s = NULL;
// 	ft_printf("%p\n",s);
// 	return (0);
// }