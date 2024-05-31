/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:47:06 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/31 05:09:33 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>

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

int	count_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	if(!tab[i])
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int	write_char_tab(va_list args, t_pf *pf)
{
	int		i;
	int		count;
	char	**tab;

	i = 0;
	tab = va_arg(args, char **);
	if (!tab)
		return (-1);
	count = count_tab(tab);
	if (count >= 10)
		i = char_tab_big(tab, pf, count);
	else
		i = char_tab(tab, pf);
	return (i);
}

int	char_tab(char **tab, t_pf *pf)
{
	int		i;
	char	*index;

	i = 0;
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
