/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:29 by lucas             #+#    #+#             */
/*   Updated: 2024/05/21 18:08:36 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	fselection(char c, va_list args, t_fpf *fpf)
{
	if (c == 'c')
		return (fcharacter(args, fpf));
	if (c == 's')
		return (fstring(args, fpf));
	if (c == 'd')
		return (fdecimale(args, fpf));
	if (c == 'i')
		return (finteger(args, fpf));
	if (c == 'u')
		return (funsinged_decimale(args, fpf));
	if (c == 'p' || c == 'x' || c == 'X')
		return (fhexa_bases(args, c, fpf));
	if (c == 't')
		return (fwrite_char_tab(args, fpf));
	if (c == '%')
		return (write(fpf->fd, "%", 1));
	return (0);
}

int	fpourcentage(t_fpf *fpf, va_list args)
{
	while (*fpf->s != '%' && *fpf->s != '\0')
	{
		fpf->neg = write(fpf->fd, *&fpf->s, 1);
		if (fpf->neg == -1)
			return (-1);
		fpf->cp++;
		fpf->s++;
	}
	if (*fpf->s == '%')
	{
		fpf->cp += fselection(*(fpf->s + 1), args, fpf);
		return (fpf->cp);
	}
	else
		return (fpf->cp);
	return (0);
}

int	ft_fprintf(int fd, const char *s, ...)
{
	va_list	args;
	t_fpf	fpf;

	va_start (args, s);
	if (!s)
		return (0);
	fpf.s = (char *)s;
	fpf.neg = 0;
	fpf.cp = 0;
	fpf.fd = fd;
	while (*fpf.s)
	{
		fpourcentage(&fpf, args);
		if (fpf.neg == -1)
			return (-1);
		else if (*fpf.s)
			fpf.s += 2;
	}
	va_end(args);
	return (fpf.cp);
}
