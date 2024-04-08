/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:42:10 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/08 23:34:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	separate(t_args *args, int y, int div)
{
	t_stk	*tmpa;
	int		i;
	int		ind;

	tmpa = args->pila;
	i = args->lst_size_a / y;
	ind = 1;
	while (div > 0)
	{
		while (args->lst_size_a > i * div)
		{
			if (tmpa->index <= i * ind)
				first_push_b(args);
			else
				rotate_a(args);
			tmpa = args->pila;
		}
		ind++;
		div--;
	}
	while (args->lst_size_a > 3)
		first_push_b(args);
}
