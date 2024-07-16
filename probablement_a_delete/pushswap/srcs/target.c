/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 08:33:03 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 08:33:15 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
