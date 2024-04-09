/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 08:27:39 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stk **from, t_stk **to)
{
	t_stk	*first;

	if (*from)
	{
		first = *from;
		*from = (*from)->next;
		if (*from)
			(*from)->prev = NULL;
		if (!*to)
		{
			*to = first;
			(*to)->prev = NULL;
			(*to)->next = NULL;
		}
		else
		{
			first->next = *to;
			first->prev = NULL;
			(*to)->prev = first;
			*to = first;
		}
	}
}

void	push_a(t_args *args)
{
	ft_printf("pa\n");
	push(&args->pilb, &args->pila);
	pos(args);
	find_target(args);
	reset_ops(args);
	push_cost(args);
}

void	push_b(t_args *args)
{
	ft_printf("pb\n");
	push(&args->pila, &args->pilb);
	pos(args);
	find_target(args);
	reset_ops(args);
	push_cost(args);
}

void	first_push_b(t_args *args)
{
	ft_printf("pb\n");
	push(&args->pila, &args->pilb);
	pos(args);
}
