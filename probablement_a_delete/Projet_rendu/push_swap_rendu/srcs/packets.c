/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:42:10 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/09 18:30:31 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	separate(t_args *args, int y, int div)
{
	int	i;
	int	ind;

	i = args->lst_size_a / y;
	ind = 1;
	sep_pack(args, div, i, ind);
	while (args->lst_size_a > 3)
		first_push_b(args);
}

void	sep_pack(t_args *args, int div, int i, int ind)
{
	t_stk	*tmpa;

	tmpa = args->pila;
	while (div > 0)
	{
		while (args->lst_size_a > i * div)
		{
			if (tmpa->index <= i * ind)
				first_push_b(args);
			else
			{
				rotate_a(args);
				args->count++;
				if (args->count >= i * ind)
				{
					ind++;
					args->count2++;
				}
			}
			tmpa = args->pila;
		}
		if (!args->count2)
			ind++;
		div--;
	}
}
