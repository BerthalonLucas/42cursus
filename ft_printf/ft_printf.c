/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:29 by lucas             #+#    #+#             */
/*   Updated: 2023/12/03 00:04:38 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int selection(const char *s, va_list args)
{
	if (*s == 'c')
		P_char(args);
	if (*s == 's')
		P_string(args);
	

	return (0);
}

int    ft_printf(const char *s, ...)
{
	va_list args;
	
	va_start (args, s);
	while (*s != '\n')
	{
		if (*s == '%')
		{
			s++;
			selection(s , args);
			s++;
		}
		write(1, *&s, 1);
		s++;
	}
	va_end(args);
	return (0);
}

int main(void)
{
	char c;
	char *s;

	c = 'v';
	s = "des strings aussi";
	ft_printf("test %s pour %c ta caisse\n", s, c);
	return (0);
}