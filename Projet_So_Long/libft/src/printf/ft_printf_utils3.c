/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:47:06 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/28 00:59:35 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	count(long int i)
{
	int	y;

	y = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i = i * -1;
		y++;
	}
	while (i > 0)
	{
		i = i / 10;
		y++;
	}
	return (y);
}

int	count_hex(unsigned long long int i)
{
	int	y;

	y = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 16;
		y++;
	}
	return (y);
}

int	write_char_tab(va_list args, t_pf *pf)
{
	int		i;
	char	*index;
	char	**tab;

	i = 0;
	tab = va_arg(args, char **);
	while (tab[i])
	{
		index = ft_itoa(i);
		pf->neg = write(1, "\nIndex [", 8);
		if (pf->neg == -1)
			return (-1);
		pf->neg = write(1, index, ft_strlen(index));
		if (pf->neg == -1)
			return (-1);
		pf->neg = write(1, "] : ", 4);
		if (pf->neg == -1)
			return (-1);
		free_ptr(index);
		pf->neg = write(1, tab[i], ft_strlen(tab[i]));
		if (pf->neg == -1)
			return (-1);
		i++;
	}
	return (i);
}
