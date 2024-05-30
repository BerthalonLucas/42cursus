/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:53:13 by lucas             #+#    #+#             */
/*   Updated: 2024/05/21 18:07:35 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	fstring(va_list args, t_fpf *fpf)
{
	char	*s;
	int		i;

	s = va_arg(args, char *);
	if (s == NULL)
		return (fpf->neg = write(fpf->fd, "(null)", 6));
	i = 0;
	while (*s)
	{
		fpf->neg = write(fpf->fd, *&s, 1);
		if (fpf->neg == -1)
			return (-1);
		s++;
		i++;
	}
	return (i);
}

int	fdecimale(va_list args, t_fpf *fpf)
{
	int	i;

	i = va_arg(args, int);
	fputnbr((long int)i, fpf);
	return (fcount((long int)i));
}

int	finteger(va_list args, t_fpf *fpf)
{
	int	i;

	i = va_arg(args, int);
	fputnbr((long int)i, fpf);
	return (fcount((long int)i));
}

int	funsinged_decimale(va_list args, t_fpf *fpf)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	fputnbr((long int)i, fpf);
	return (fcount((long int)i));
}

int	fputnbr(long int i, t_fpf *fpf)
{
	if (i == -2147483648)
		return (write(fpf->fd, "-2147483648", 11));
	if (i < 0)
	{
		fpf->neg = write(fpf->fd, "-", 1);
		if (fpf->neg == -1)
			return (-1);
		i *= -1;
	}
	if (i >= 10)
		fputnbr(i / 10, fpf);
	i = i % 10 + '0';
	fpf->neg = write(fpf->fd, (const char *)&i, 1);
	if (fpf->neg == -1)
		return (-1);
	return (0);
}
