/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:53:13 by lucas             #+#    #+#             */
/*   Updated: 2023/12/03 00:08:40 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int P_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (0);
}
int *P_string(va_list args)
{
	char *s;
	
	s = va_arg(args, char *);
	while (*s)
	{
		write(1, *&s, 1);
		s++;
	}
	return (0);
}
int *P_pointer(va_list args)
{
	void *p;
	
		
}
// int P_decimale(long int i)
// {

// }
// int P_interger(int i)
// {
	
// }
