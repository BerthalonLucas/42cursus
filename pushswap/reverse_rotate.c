/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:46 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/22 14:25:33 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stk *stack)
{
	t_stk	*last;
	t_stk	*before_last;
	
	if (stack && stack->next)
	{
		last = stack;
		while (last->next != NULL)
			last = last->next;
		before_last = last->prev;
		before_last->next = NULL;
		last->prev = NULL;
		last->next = stack;
		stack->prev = last;
		stack = last;
	}
}
void reverse_rotate_a(t_args *args)
{
    ft_printf("rra\n");
    reverse_rotate(args->pila);
}
void reverse_rotate_b(t_args *args)
{
    ft_printf("rrb\n");
    reverse_rotate(args->pilb);
}
void rrr(t_args *args)
{
    ft_printf("rrr\n");
    reverse_rotate(args->pila);
    reverse_rotate(args->pilb);
}