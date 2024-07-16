/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/09 20:09:16 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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
	push(&args->pilb, &args->pila);
}

void	push_b(t_args *args)
{
	push(&args->pila, &args->pilb);
}
