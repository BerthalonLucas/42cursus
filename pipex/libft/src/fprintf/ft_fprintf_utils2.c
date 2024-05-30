/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:53:10 by lucas             #+#    #+#             */
/*   Updated: 2024/05/21 18:08:05 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	fcharacter(va_list args, t_fpf *fpf)
{
	char	c;

	c = va_arg(args, int);
	return (fpf->neg = write(fpf->fd, &c, 1));
}

int	fhexa_lower(unsigned long long i, char *base, t_fpf *fpf)
{
	if (i >= 16)
		fhexa_lower(i / 16, base, fpf);
	fpf->neg = write(fpf->fd, &base[i % 16], 1);
	if (fpf->neg == -1)
		return (-1);
	return (fcount_hex(i));
}

int	fhexa_upper(unsigned long long i, char *base, t_fpf *fpf)
{
	if (i >= 16)
		fhexa_upper(i / 16, base, fpf);
	fpf->neg = write(fpf->fd, &base[i % 16], 1);
	if (fpf->neg == -1)
		return (-1);
	return (fcount_hex(i));
}

int	fpointer(unsigned long long i, char *base, t_fpf *fpf)
{
	if (i >= 16)
		fpointer(i / 16, base, fpf);
	fpf->neg = write(fpf->fd, &base[i % 16], 1);
	if (fpf->neg == -1)
		return (-1);
	return (2 + fcount_hex(i));
}

int	fhexa_bases(va_list args, char c, t_fpf *fpf)
{
	unsigned long long	n;

	if (c == 'x')
	{
		n = va_arg(args, unsigned int);
		return (fhexa_lower(n, "0123456789abcdef", fpf));
	}
	if (c == 'X')
	{
		n = va_arg(args, unsigned int);
		return (fhexa_upper(n, "0123456789ABCDEF", fpf));
	}
	if (c == 'p')
	{
		n = va_arg(args, unsigned long long);
		if ((void *)n == NULL)
			return (fpf->neg = write(fpf->fd, "(nil)", 5));
		fpf->neg = write(fpf->fd, "0x", 2);
		if (fpf->neg == -1)
			return (-1);
		return (fpointer(n, "0123456789abcdef", fpf));
	}
	return (0);
}
