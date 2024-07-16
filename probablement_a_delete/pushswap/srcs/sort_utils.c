/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:11:17 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 08:36:07 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	sorted(t_args *args)
{
	t_stk	*tmp;

	tmp = args->pila;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

t_stk	*find_smallest(t_args *args)
{
	t_stk	*tmp;
	t_stk	*ret;
	int		smallest;

	tmp = args->pila;
	smallest = INT_MAX;
	ret = NULL;
	while (tmp)
	{
		if (tmp->nbr < smallest)
		{
			smallest = tmp->nbr;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_stk	*find_biggest(t_args *args)
{
	t_stk	*tmp;
	t_stk	*ret;
	int		biggest;

	tmp = args->pila;
	biggest = INT_MIN;
	ret = NULL;
	while (tmp)
	{
		if (tmp->nbr > biggest)
		{
			biggest = tmp->nbr;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_stk	*find_cheapest(t_stk *pilb)
{
	t_stk	*tmpb;
	t_stk	*cheapest_s;

	tmpb = pilb;
	cheapest_s = tmpb;
	while (tmpb)
	{
		if (tmpb->push_cost < cheapest_s->push_cost)
			cheapest_s = tmpb;
		tmpb = tmpb->next;
	}
	return (cheapest_s);
}

void	reset_ops(t_args *args)
{
	t_stk	*tmpb;

	tmpb = args->pilb;
	while (tmpb)
	{
		tmpb->ra = 0;
		tmpb->rb = 0;
		tmpb->rr = 0;
		tmpb->rra = 0;
		tmpb->rrb = 0;
		tmpb->rrr = 0;
		tmpb = tmpb->next;
	}
}
