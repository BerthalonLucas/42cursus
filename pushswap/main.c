/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:30:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/15 03:55:56 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_stk pila;
	t_stk pilb;

	pila.nbr = 42;
	pila.index = 1;
	pila.next = NULL;
	pila.prev = NULL;
	pila.next = &pilb;
	pilb.nbr = 24;
	pilb.next = NULL;
	pilb.prev = &pila;
	
	return (ft_printf("pila nbr %d\n", pila.nbr));
}