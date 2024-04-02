/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/01 21:05:59 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stk **stack)
{
	t_stk	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}
void swap_a(t_args *args)
{
    ft_printf("sa\n");
    swap(&args->pila);
	pos(args);
}
void swap_b(t_args *args)
{
    ft_printf("sb\n");
    swap(&args->pilb);
	pos(args);
}
void ss(t_args *args)
{
    ft_printf("ss\n");
    swap(&args->pila);
    swap(&args->pilb);
	pos(args);
}
