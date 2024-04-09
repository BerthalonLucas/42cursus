/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 08:33:25 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 08:33:32 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	t_stk	*tmp;

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
