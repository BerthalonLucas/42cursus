/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:15:08 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/03 00:04:19 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_args(t_args *args)
{
	args->pila = NULL;
	args->pilb = NULL;
	args->lst_size_a = 0;
	args->lst_size_b = 0;
}
void init_chain(t_stk *pile, int nbr)
{
	pile->target = NULL;
	pile->next = NULL;
	pile->prev = NULL;
	pile->above_mediane = false;
	pile->nbr = nbr;
	pile->push_cost = 0;
	pile->index = 0;
	pile->pos = 0;
}