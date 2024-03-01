/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:53:13 by lucas             #+#    #+#             */
/*   Updated: 2024/03/01 02:43:52 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string(va_list args, t_pf *pf)
{
	char	*s;
	int		i;

	s = va_arg(args, char *);
	if (s == NULL)
		return (pf->neg = write(1, "(null)", 6));
	i = 0;
	while (*s)
	{
		pf->neg = write(1, *&s, 1);
		if (pf->neg == -1)
			return (-1);
		s++;
		i++;
	}
	return (i);
}

int	decimale(va_list args, t_pf *pf)
{
	int	i;

	i = va_arg(args, int);
	putnbr((long int)i, pf);
	return (count((long int)i));
}

int	integer(va_list args, t_pf *pf)
{
	int	i;

	i = va_arg(args, int);
	putnbr((long int)i, pf);
	return (count((long int)i));
}

int	unsinged_decimale(va_list args, t_pf *pf)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	putnbr((long int)i, pf);
	return (count((long int)i));
}

int	putnbr(long int i, t_pf *pf)
{
	if (i == -2147483648)
		return (write(1, "-2147483648", 11));
	if (i < 0)
	{
		pf->neg = write(1, "-", 1);
		if (pf->neg == -1)
			return (-1);
		i *= -1;
	}
	if (i >= 10)
		putnbr(i / 10, pf);
	i = i % 10 + '0';
	pf->neg = write(1, (const char *)&i, 1);
	if (pf->neg == -1)
		return (-1);
	return (0);
}
