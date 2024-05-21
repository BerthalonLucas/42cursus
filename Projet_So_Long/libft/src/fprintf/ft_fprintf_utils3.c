/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:47:06 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/21 17:23:18 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	fcount(long int i)
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

int	fcount_hex(unsigned long long int i)
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

int	fwrite_char_tab(va_list args, t_fpf *fpf)
{
	int		i;
	char	*index;
	char	**tab;

	i = 0;
	tab = va_arg(args, char **);
	while (tab[i])
	{
		index = ft_itoa(i);
		fpf->neg = write(fpf->fd, "\nIndex [", 8);
		if (fpf->neg == -1)
			return (-1);
		fpf->neg = write(fpf->fd, index, ft_strlen(index));
		if (fpf->neg == -1)
			return (-1);
		fpf->neg = write(fpf->fd, "] : ", 4);
		if (fpf->neg == -1)
			return (-1);
		free(index);
		fpf->neg = write(fpf->fd, tab[i], ft_strlen(tab[i]));
		if (fpf->neg == -1)
			return (-1);
		i++;
	}
	return (i);
}
