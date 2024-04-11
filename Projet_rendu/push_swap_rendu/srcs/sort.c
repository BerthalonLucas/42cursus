/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:03:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/11 02:17:08 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_args *args)
{
	int	size;

	size = args->lst_size_a;
	if (size == 2)
	{
		if (args->pila->nbr > args->pila->next->nbr)
			swap_a(args);
	}
	else if (size == 3)
		sort_three(args);
	else
		sort_big(args);
}

void	sort_three(t_args *args)
{
	int	a;
	int	b;
	int	c;

	a = args->pila->index;
	b = args->pila->next->index;
	c = args->pila->next->next->index;
	if (a > b && b < c && a < c)
		swap_a(args);
	else if (a > b && b > c && a > c)
	{
		swap_a(args);
		reverse_rotate_a(args);
	}
	else if (a > b && b < c && a > c)
		rotate_a(args);
	else if (a < b && b > c && a < c)
	{
		swap_a(args);
		rotate_a(args);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(args);
}

void	sort_big(t_args *args)
{
	if (args->lst_size_a >= 100 && args->lst_size_a < 500)
		separate(args, 3, 2);
	else if (args->lst_size_a >= 500)
		separate(args, 5, 4);
	else
	{
		while (args->lst_size_a > 3)
			first_push_b(args);
	}
	sort_three(args);
	find_target(args);
	push_cost(args);
	do_ops(args);
}
