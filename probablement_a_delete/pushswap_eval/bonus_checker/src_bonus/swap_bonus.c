/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/09 20:09:30 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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

void	swap_a(t_args *args)
{
	swap(&args->pila);
}

void	swap_b(t_args *args)
{
	swap(&args->pilb);
}

void	ss(t_args *args)
{
	swap(&args->pila);
	swap(&args->pilb);
}
