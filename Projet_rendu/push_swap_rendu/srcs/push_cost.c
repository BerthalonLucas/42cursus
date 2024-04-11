/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 08:34:03 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 08:34:24 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_cost(t_args *args)
{
	t_stk	*tmpb;

	tmpb = args->pilb;
	if (args->pilb)
	{
		while (tmpb)
		{
			if (tmpb->target->above_mediane && tmpb->above_mediane)
				push_cost_above(tmpb);
			else if (!(tmpb->target->above_mediane) && !(tmpb->above_mediane))
				push_cost_bellow(args, tmpb);
			else
				push_cost_else(args, tmpb);
			tmpb = tmpb->next;
		}
	}
}

void	push_cost_above(t_stk *tmpb)
{
	int	size_diff_a;
	int	size_diff_b;

	size_diff_b = tmpb->pos;
	size_diff_a = tmpb->target->pos;
	if (size_diff_b == size_diff_a)
	{
		tmpb->push_cost = size_diff_a;
		tmpb->rr = size_diff_a;
	}
	else if (size_diff_b < size_diff_a)
	{
		tmpb->push_cost = size_diff_b + (size_diff_a - size_diff_b);
		tmpb->rr = size_diff_b;
		tmpb->ra = size_diff_a - size_diff_b;
	}
	else if (size_diff_b > size_diff_a)
	{
		tmpb->push_cost = size_diff_a + (size_diff_b - size_diff_a);
		tmpb->rr = size_diff_a;
		tmpb->rb = size_diff_b - size_diff_a;
	}
}

void	push_cost_bellow(t_args *args, t_stk *tmpb)
{
	int	size_diff_a;
	int	size_diff_b;

	size_diff_b = args->lst_size_b - tmpb->pos;
	size_diff_a = args->lst_size_a - tmpb->target->pos;
	if (size_diff_b == size_diff_a)
	{
		tmpb->push_cost = size_diff_b;
		tmpb->rrr = size_diff_b;
	}
	else if (size_diff_b < size_diff_a)
	{
		tmpb->push_cost = size_diff_b + (size_diff_a - size_diff_b);
		tmpb->rrr = size_diff_b;
		tmpb->rra = size_diff_a - size_diff_b;
	}
	else
	{
		tmpb->push_cost = size_diff_a + (size_diff_b - size_diff_a);
		tmpb->rrr = size_diff_a;
		tmpb->rrb = size_diff_b - size_diff_a;
	}
}

void	push_cost_else(t_args *args, t_stk *tmpb)
{
	int	size_diff_a;
	int	size_diff_b;

	size_diff_a = args->lst_size_a - tmpb->target->pos;
	size_diff_b = args->lst_size_b - tmpb->pos;
	if (tmpb->above_mediane)
	{
		tmpb->push_cost = tmpb->pos + size_diff_a;
		tmpb->rb = tmpb->pos;
		tmpb->rra = args->lst_size_a - tmpb->target->pos;
	}
	else
	{
		tmpb->push_cost = tmpb->target->pos + size_diff_b;
		tmpb->ra = tmpb->target->pos;
		tmpb->rrb = args->lst_size_b - tmpb->pos;
	}
}
