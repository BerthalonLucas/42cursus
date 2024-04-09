/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:20:42 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 09:01:24 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	ft_printf("ra\n");
	rotate(&args->pila);
	pos(args);
}

void	rotate_b(t_args *args)
{
	ft_printf("rb\n");
	rotate(&args->pilb);
	pos(args);
}

void	rr(t_args *args)
{
	ft_printf("rr\n");
	rotate(&args->pila);
	rotate(&args->pilb);
	pos(args);
}
