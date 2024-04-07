/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 03:51:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 08:35:45 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	iter_index(t_args *args)
{
	t_stk	*tmpa;
	int		pos;
	bool	mediane;

	tmpa = args->pila;
	while (tmpa->index != 0)
		tmpa = tmpa->next;
	mediane = tmpa->above_mediane;
	pos = tmpa->pos;
	final_sort(args, pos, mediane);
}

void	final_sort(t_args *args, int pos, bool mediane)
{
	int	count_revers;

	if (mediane)
	{
		while (pos > 0)
		{
			rotate_a(args);
			pos--;
		}
	}
	else
	{
		count_revers = args->lst_size_a - pos;
		while (count_revers > 0)
		{
			reverse_rotate_a(args);
			count_revers--;
		}
	}
}
