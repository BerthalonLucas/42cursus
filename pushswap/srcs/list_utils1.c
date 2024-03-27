/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:55:26 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/26 23:07:45 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_list_add_front(t_args *args, t_stk *new, char pile)
{
	t_stk *first;

	if (pile == 'a')
	{
		if(!args->pila)
			args->pila = new;
		else
		{
			first = args->pila;
			args->pila = new;
			new->next = first;
			first->prev = new;
		}
	}
	else
	{
		if(!args->pilb)
			args->pilb = new;
		else
		{
			first = args->pilb;
			args->pilb = new;
			new->next = first;
			first->prev = new;
		}
	}	
}