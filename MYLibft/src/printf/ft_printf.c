/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:29 by lucas             #+#    #+#             */
/*   Updated: 2024/03/14 00:25:59 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	selection(char c, va_list args, t_pf *pf)
{
	if (c == 'c')
		return (character(args, pf));
	if (c == 's')
		return (string(args, pf));
	if (c == 'd')
		return (decimale(args, pf));
	if (c == 'i')
		return (integer(args, pf));
	if (c == 'u')
		return (unsinged_decimale(args, pf));
	if (c == 'p' || c == 'x' || c == 'X')
		return (hexa_bases(args, c, pf));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	pourcentage(t_pf *pf, va_list args)
{
	while (*pf->s != '%' && *pf->s != '\0')
	{
		pf->neg = write(1, *&pf->s, 1);
		if (pf->neg == -1)
			return (-1);
		pf->cp++;
		pf->s++;
	}
	if (*pf->s == '%')
	{
		pf->cp += selection(*(pf->s + 1), args, pf);
		return (pf->cp);
	}
	else
		return (pf->cp);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_pf	pf;

	va_start (args, s);
	if (!s)
		return (0);
	pf.s = (char *)s;
	pf.neg = 0;
	pf.cp = 0;
	while (*pf.s)
	{
		pourcentage(&pf, args);
		if (pf.neg == -1)
			return (-1);
		else if (*pf.s)
			pf.s += 2;
	}
	va_end(args);
	return (pf.cp);
}
