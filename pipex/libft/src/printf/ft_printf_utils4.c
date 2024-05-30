/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:47:06 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/28 23:09:57 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	char_tab_big(char **tab, t_pf *pf, int count)
{
	int		i;
	char	*index;

	i = 0;
	while (tab[i])
	{
		index = ft_itoa(i);
		pf->neg = write(1, "\nIndex [", 8);
		if (i <= 9 && count > 10)
			pf->neg = write(1, "0", 1);
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
