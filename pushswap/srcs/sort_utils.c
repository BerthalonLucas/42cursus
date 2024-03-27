/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:11:17 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/27 04:01:41 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool sorted(t_args *args)
{
	t_stk *tmp;

	tmp = args->pila;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	find_smallest(t_args *args)
{
	t_stk *tmp;
	int smallest;

	tmp = args->pila;
	smallest = tmp->index;
	while (tmp)
	{
		if (tmp->index < smallest)
			smallest = tmp->index;
		tmp = tmp->next;
	}
	return (smallest);
}
void	pos(t_args *args)
{
	t_stk *tmp;
	int i;

	i = 0;
	if (args->pila)
	{
		tmp = args->pila;
		while (tmp)
		{
			tmp->pos = i;
			i++;
			tmp = tmp->next;
		}	
	}
	if (args->pilb)
	{
		tmp = args->pilb;
		i = 0;
		while (tmp)
		{
			tmp->pos = i;
			i++;
			tmp = tmp->next;
		}
	}
}
void 	push_cost(t_args *args)
{
	t_stk *tmp;
	int i;

	i = 0;
	if (args->pila)
	{
		tmp = args->pila;
		while (tmp)
		{
			tmp->push_cost = i;
			i++;
			tmp = tmp->next;
		}	
	}
	if (args->pilb)
	{
		tmp = args->pilb;
		i = 0;
		while (tmp)
		{
			tmp->push_cost = i;
			i++;
			tmp = tmp->next;
		}
	}
}