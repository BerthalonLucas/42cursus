/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:53:10 by lucas             #+#    #+#             */
/*   Updated: 2024/02/22 19:07:56 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	character(va_list args, t_pf *pf)
{
	char	c;

	c = va_arg(args, int);
	return (pf->neg = write(1, &c, 1));
}

int	hexa_lower(unsigned long long i, char *base, t_pf *pf)
{
	if (i >= 16)
		hexa_lower(i / 16, base, pf);
	pf->neg = write(1, &base[i % 16], 1);
	if (pf->neg == -1)
		return (-1);
	return (count_hex(i));
}

int	hexa_upper(unsigned long long i, char *base, t_pf *pf)
{
	if (i >= 16)
		hexa_upper(i / 16, base, pf);
	pf->neg = write(1, &base[i % 16], 1);
	if (pf->neg == -1)
		return (-1);
	return (count_hex(i));
}

int	pointer(unsigned long long i, char *base, t_pf *pf)
{
	if (i >= 16)
		pointer(i / 16, base, pf);
	pf->neg = write(1, &base[i % 16], 1);
	if (pf->neg == -1)
		return (-1);
	return (2 + count_hex(i));
}

int	hexa_bases(va_list args, char c, t_pf *pf)
{
	unsigned long long	n;

	if (c == 'x')
	{
		n = va_arg(args, unsigned int);
		return (hexa_lower(n, "0123456789abcdef", pf));
	}
	if (c == 'X')
	{
		n = va_arg(args, unsigned int);
		return (hexa_upper(n, "0123456789ABCDEF", pf));
	}
	if (c == 'p')
	{
		n = va_arg(args, unsigned long long);
		if ((void *)n == NULL)
			return (pf->neg = write(1, "(nil)", 5));
		pf->neg = write(1, "0x", 2);
		if (pf->neg == -1)
			return (-1);
		return (pointer(n, "0123456789abcdef", pf));
	}
	return (0);
}
