/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:56:13 by root              #+#    #+#             */
/*   Updated: 2024/04/09 20:08:26 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	init_args(t_args *args)
{
	args->pila = NULL;
	args->pilb = NULL;
	args->lst_size_a = 0;
	args->lst_size_b = 0;
}

void	init_chain(t_stk *pile, int nbr)
{
	pile->next = NULL;
	pile->prev = NULL;
	pile->nbr = nbr;
	pile->index = 0;
}
