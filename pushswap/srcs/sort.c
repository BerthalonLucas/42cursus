/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:03:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/05 07:37:57 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort(t_args *args)
{
	int	size;

	size = args->lst_size_a;
	if (size == 2)
	{
		if (args->pila->nbr > args->pila->next->nbr)
			swap_a(args);
	}
	else if (size == 3)
		sort_three(args);
	else if (size == 4)
		sort_four(args);
	else if (size == 5)
		sort_five(args);
	else
		sort_big(args);
}
void sort_three(t_args *args)
{
	int	a;
	int	b;
	int	c;

	a = args->pila->index;
	b = args->pila->next->index;
	c = args->pila->next->next->index;
	if (a > b && b < c && a < c) //  cas ou 1 / 0 / 2 ---> 0 / 1 / 2
		swap_a(args);
	else if (a > b && b > c && a > c) // cas ou 2 / 1 / 0 ---> 1 / 2 / 0 ---> 0 / 1 / 2
	{
		swap_a(args);
		reverse_rotate_a(args);
	}
	else if (a > b && b < c && a > c) // cas ou 2 / 0 / 1 ---> 0 / 1 / 2
		rotate_a(args);
	else if (a < b && b > c && a < c) // cas ou 0 / 2 / 1 ---> 2 / 0 / 1 ---> 0 / 1 / 2
	{
		swap_a(args);
		rotate_a(args);
	}
	else if (a < b && b > c && a > c) // cas ou 1 / 2 / 0 ---> 0 / 1 / 2
		reverse_rotate_a(args);
}

void	sort_four(t_args *args)
{
	int smallest;

	smallest = find_smallest(args)->nbr;
	while (args->pila->nbr != smallest)
		rotate_a(args);
	push_b(args);
	sort_three(args);
	push_a(args);
}
void	sort_five(t_args *args)
{
	int smallest;

	smallest = find_smallest(args)->nbr;
	while (args->pila->nbr != smallest)
		rotate_a(args);
	push_b(args);
	find_target(args);
	sort_four(args);
	push_a(args);
}

void	sort_big(t_args *args)
{
	int i;

	i = args->lst_size_a;
	while (i > 3)
	{
		first_push_b(args);
		i--;
	}
	sort_three(args);
	find_target(args);
	push_cost(args);
	do_ops(args);
}
void	do_ops(t_args *args)
{
	// t_stk *tmpb;
	t_stk *cheapest;

	// tmpb = args->pilb;
	// ft_printf("======================PILB avant====================\n");
	// print_list(tmpb);
	// ft_printf("======================PILB apres====================\n");
	// print_list(tmpb);
	while (args->lst_size_b > 0)
	{
		cheapest = find_cheapest(args->pilb);
		do_rr_and_rrr(args, cheapest);
		do_ra_and_rra(args, cheapest);
		do_rb_and_rrb(args, cheapest);
		push_a(args);
		// tmpb = tmpb->next;
	}
}
void do_ra_and_rra(t_args *args, t_stk *cheapest)
{
	while (cheapest->ra > 0)
	{
		rotate_a(args);
		cheapest->ra--;
	}
	while (cheapest->rra > 0)
	{
		reverse_rotate_a(args);
		cheapest->rra--;
	}
}
void do_rb_and_rrb(t_args *args, t_stk *cheapest)
{
	while (cheapest->rb > 0)
	{
		rotate_b(args);
		cheapest->rb--;
	}
	while (cheapest->rrb > 0)
	{
		reverse_rotate_b(args);
		cheapest->rrb--;
	}
}

void	do_rr_and_rrr(t_args *args, t_stk *cheapest)
{
	while (cheapest->rr > 0)
	{
		rr(args);
		cheapest->rr--;
	}
	while (cheapest->rrr > 0)
	{
		rrr(args);
		cheapest->rrr--;
	}
}
