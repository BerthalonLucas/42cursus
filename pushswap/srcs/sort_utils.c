/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:11:17 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/03 21:53:12 by lberthal         ###   ########.fr       */
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

t_stk	*find_smallest(t_args *args)
{
	t_stk *tmp;
	t_stk *ret;
	int smallest;

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
	t_stk *tmp;
	t_stk *ret;
	int biggest;

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
	pos_b(args);
	ft_lst_size(args);
	above_mediane(args);
}
void pos_b(t_args *args)
{
	t_stk *tmp;
	int i;

	i = 0;
	if (args->pilb)
	{
		tmp = args->pilb;
		while (tmp)
		{
			tmp->pos = i;
			i++;
			tmp = tmp->next;
		}
	}
}
t_stk	*find_neerest_bigger(t_args *args, int number)
{
	t_stk	*tmpa;
	t_stk	*neerest_bigger;

	tmpa = args->pila;
	neerest_bigger = NULL;
	while (tmpa)
	{
		if (tmpa->nbr > number)
		{
			if (neerest_bigger && (tmpa->nbr < neerest_bigger->nbr))
			{
				neerest_bigger = tmpa;
			}
			else if (!neerest_bigger)
				neerest_bigger = tmpa;	
		}
		tmpa = tmpa->next;
	}
	return (neerest_bigger);
}
void	find_target(t_args *args)
{
	t_stk	*tmpb;
	
	if (args->pilb)
	{
		tmpb = args->pilb;
		while (tmpb)
		{
			tmpb->target = find_neerest_bigger(args, tmpb->nbr);
			if (!tmpb->target)
				tmpb->target = find_smallest(args);
			tmpb = tmpb->next;
		}
	}
}
void	above_mediane(t_args *args)
{
	t_stk	*tmp;
	
	if (args->pila)
	{
		tmp = args->pila;
		while (tmp)
		{
			if (tmp->pos <= (args->lst_size_a / 2))
				tmp->above_mediane = true;
			else
				tmp->above_mediane = false;
			tmp = tmp->next;
		}
	}
	above_mediane_b(args);
}
void	above_mediane_b(t_args *args)
{
	t_stk *tmp;
	
	if (args->pilb)
	{
		tmp = args->pilb;
		while (tmp)
		{
			if (tmp->pos <= (args->lst_size_b / 2))
				tmp->above_mediane = true;
			else
				tmp->above_mediane = false;
			tmp = tmp->next;
		}
	}
}

// void	push_cost(t_args *args)
// {
	
// }