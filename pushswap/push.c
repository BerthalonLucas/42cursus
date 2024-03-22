/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/22 14:49:33 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_args *args, t_stk *from, t_stk *to)
{
	t_stk	*first;

	if (from)
	{
		first = from;
		from = from->next;
		if (from)
			from->prev = NULL;
		if (!to)
		{
			ft_list_add_back(args, to, 'b');
			first->next = to;
		}
		if (to)
			to->prev = first;
		to = first;

	}
}
void push_a(t_args *args)
{
    ft_printf("pa\n");
    push(args, args->pilb, args->pila);
}

void push_b(t_args *args)
{
    ft_printf("pb\n");
    push(args, args->pila, args->pilb);
}