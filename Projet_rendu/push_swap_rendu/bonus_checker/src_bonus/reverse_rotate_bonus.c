/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:46 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/09 20:09:21 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	reverse_rotate(t_stk **stack)
{
	t_stk	*tmp;
	t_stk	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	tmp = last->prev;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	tmp->next = NULL;
}

void	reverse_rotate_a(t_args *args)
{
	reverse_rotate(&args->pila);
}

void	reverse_rotate_b(t_args *args)
{
	reverse_rotate(&args->pilb);
}

void	rrr(t_args *args)
{
	reverse_rotate(&args->pila);
	reverse_rotate(&args->pilb);
}
