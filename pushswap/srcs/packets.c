/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:42:10 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 23:52:38 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void separate(t_args *args)
{
	t_stk *tmpa;
	int i;

	tmpa = args->pila;
	i = args->lst_size_a / 2;
	while (args->lst_size_a > i)
	{
		if (tmpa->index <= i)
			first_push_b(args);
		else
			rotate_a(args);
		tmpa = args->pila;
	}
	while (args->lst_size_a > 3)
		first_push_b(args);
}

void	separate_three(t_args *args)
{
	t_stk *tmpa;
	int i;

	tmpa = args->pila;
	i = args->lst_size_a / 3;
	while (args->lst_size_a > i * 2)
	{
		if (tmpa->index <= i)
			first_push_b(args);
		else
			rotate_a(args);
		tmpa = args->pila;
	}
	while (args->lst_size_a > i)
	{
		if (tmpa->index <= i * 2)
			first_push_b(args);
		else
			rotate_a(args);
		tmpa = args->pila;
	}
	while (args->lst_size_a > 3)
		first_push_b(args);
}

void	sep_test(t_args *args)
{
	t_stk *tmpa;
	int i;
	int div;
	int ind;
	// int count;

	tmpa = args->pila;
	i = args->lst_size_a / 5;
	div = 4;
	ind = 1;
	// count = 0;
	while (div > 0)
	{
		while (args->lst_size_a > i * div)
		{
			if (tmpa->index <= i * ind)
				first_push_b(args);
			else
				rotate_a(args);

			tmpa = args->pila;
			// count++;
			// ft_printf("i: %d, div: %d, ind: %d, lst_size_a: %d nbr: %d\n", i, div, ind, args->lst_size_a, tmpa->nbr);
			// if (count >= 40000)
			// 	break;
		}
		ind++;
		div--;
	}
	// if (count >= 40000)
	// 	return ;
	while (args->lst_size_a > 3)
		first_push_b(args);
}

// bool	find_next_in_scoop(t_stk *pila, int scoop)
// {
// 	t_stk *tmp;
// 	int above_mediane;
// 	int below_mediane;

// 	tmp = pila;
// 	above_mediane = 0;
// 	below_mediane = 0;
// 	while (tmp)
// 	{
// 		if ((tmp->index <= scoop) && tmp->above_mediane)
// 			above_mediane++;
// 		else if ((tmp->index <= scoop) && !tmp->above_mediane)
// 			below_mediane++;
// 		tmp = tmp->next;
// 	}
// 	if (above_mediane > below_mediane)
// 		return (true);
// 	else
// 		return (false);
// }