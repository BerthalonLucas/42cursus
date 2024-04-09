/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:42 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/09 20:09:26 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	rotate(t_stk **stack)
{
	t_stk	*tmp;
	t_stk	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = find_last(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = last;
	last->next = tmp;
}

void	rotate_a(t_args *args)
{
	rotate(&args->pila);
}

void	rotate_b(t_args *args)
{
	rotate(&args->pilb);
}

void	rr(t_args *args)
{
	rotate(&args->pila);
	rotate(&args->pilb);
}
