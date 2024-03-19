/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ox_m_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:13:20 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/14 00:42:11 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ox_m(size_t xxx)
{
	static int	i;

	i = 0;
	if (i == 9)
	{
		ft_printf("[%d]attention... 🔨 ", i);
		return (NULL);
	}
	i++;
	ft_printf("\t💢💣💥 !");
	return (malloc(xxx));
}

size_t	ox_r(int fdp, void *b, int len)
{
	static int	i;

	i = 0;
	if (i == 9)
		return (-1);
	i++;
	return (read(fdp, b, len));
}
