/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:55:53 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/14 02:55:54 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stk **stack)
{
	t_stk	*first;
	t_stk	*second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = first->next;
		first->next = second->next;
		if (second->next != NULL)
			second->next->prev = first;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
		*stack = second;
	}
}

void	push(t_stk *from, t_stk *to)
{
	t_stk	*first;

	if (*from)
	{
		first = *from;
		*from = (*from)->next;
		if (*from)
			(*from)->prev = NULL;
		first->next = *to;
		if (*to)
			(*to)->prev = first;
		*to = first;
	}
}

void	rotate(t_stk *stack)
{
	t_stk	*first;
	t_stk	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
}

void	reverse_rotate(t_stk *stack)
{
	t_stk	*last;
	t_stk	*before_last;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		before_last = last->prev;
		before_last->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}

bool	parse_args(int argc, char **argv, t_args *args)
{
    int i;
    int nbr;
    t_stk *new_node;
    t_stk *last_node = NULL;

    args->pila = NULL;
    args->pilb = NULL;
    for (i = 1; i < argc; i++)
    {
        if (!is_number(argv[i]) || !is_in_int_range(argv[i]))
            return false; // Vérification simplifiée
        nbr = ft_atoi(argv[i]);
        if (find_in_stack(args->pila, nbr))
            return false; // Doublon trouvé
        new_node = create_new_node(nbr);
        if (!args->pila)
            args->pila = new_node;
        else
            last_node->next = new_node;
        new_node->prev = last_node;
        last_node = new_node;
    }
    return true;
}
