/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:47:06 by lberthal          #+#    #+#             */
/*   Updated: 2023/12/10 20:08:49 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count(long int i)
{
	int y;
	y = 0;
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

int count_hex(long int i)
{
	int y;
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
