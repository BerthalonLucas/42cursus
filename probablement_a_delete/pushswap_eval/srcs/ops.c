/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 08:06:57 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 08:28:22 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_ops(t_args *args)
{
	t_stk	*cheapest;

	while (args->lst_size_b > 0)
	{
		cheapest = find_cheapest(args->pilb);
		do_rr_and_rrr(args, cheapest);
		do_ra_and_rra(args, cheapest);
		do_rb_and_rrb(args, cheapest);
		push_a(args);
	}
	iter_index(args);
}

void	do_ra_and_rra(t_args *args, t_stk *cheapest)
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

void	do_rb_and_rrb(t_args *args, t_stk *cheapest)
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
