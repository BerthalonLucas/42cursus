/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:15:08 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/27 03:54:14 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_args(t_args *args)
{
	args->pila = NULL;
	args->pilb = NULL;
}
void init_chain(t_stk *pile, int nbr)
{
	pile->target = NULL;
	pile->next = NULL;
	pile->prev = NULL;
	pile->nbr = nbr;
	pile->push_cost = 0;
	pile->index = 0;
	pile->pos = 0;
}