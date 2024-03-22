/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:42 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/22 14:25:08 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stk *stack)
{
	t_stk	*first;
	t_stk	*last;

	if (stack && stack->next)
	{
		first = stack;
		stack = stack->next;
		stack->prev = NULL;
		last = stack;
		while (last->next != NULL)
			last = last->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
}
void rotate_a(t_args *args)
{
    ft_printf("ra\n");
    rotate(args->pila);
}

void rotate_b(t_args *args)
{
    ft_printf("rb\n");
    rotate(args->pilb);
}
void rr(t_args *args)
{
    ft_printf("rr\n");
    rotate(args->pila);
    rotate(args->pilb);
}