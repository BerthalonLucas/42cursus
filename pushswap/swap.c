/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/22 14:36:07 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stk *stack)
{
	t_stk	*first;
	t_stk	*second;

	if (stack && stack->next)
	{
		first = stack;
		second = first->next;
		first->next = second->next;
		if (second->next != NULL)
			second->next->prev = first;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
		stack = second;
	}
}
void swap_a(t_args *args)
{
    ft_printf("sa\n");
    swap(args->pila);
}
void swap_b(t_args *args)
{
    ft_printf("sb\n");
    swap(args->pilb);
}
void ss(t_args *args)
{
    ft_printf("ss\n");
    swap(args->pila);
    swap(args->pilb);
}
