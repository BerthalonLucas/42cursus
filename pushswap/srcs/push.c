/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/27 02:00:28 by lberthal         ###   ########.fr       */
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

/* push a => b
	tmp = a
	a = a->next
	a->prev = NULL
	b->prev = tmp
	tmp->next = b
	b = tmp
	b->prev = NULL
*/

void push_a(t_args *args)
{
    ft_printf("pa\n");
    push(&args->pilb, &args->pila);
}

void push_b(t_args *args)
{
    ft_printf("pb\n");
    push(&args->pila, &args->pilb);
}