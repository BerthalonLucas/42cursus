/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:30:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/05 07:19:03 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_list(t_stk *list)
{
	t_stk *tmp = list;
	while (tmp)
	{
		ft_printf("--------------------\n");
		ft_printf("| {nbr[%d]}  {index[%d]}  {pos[%d]}  {cost[%d]} |\n", tmp->nbr, tmp->index, tmp->pos, tmp->push_cost);
		ft_printf("| {ra[%d]}  {rra[%d]}  {rb[%d]}  {rrb[%d]}  {rr[%d]}  {rrr[%d]} |\n", tmp->ra, tmp->rra, tmp->rb, tmp->rrb, tmp->rr, tmp->rrr);
		ft_printf("--------------------\n");
		tmp = tmp->next;
	}
}

int main(int ac, char **av)
{
	t_args	args;
	
	init_args(&args);
	ft_parsing(ac, av);
	ft_insert(&args, av, ac);
	if (!sorted(&args))
	{
		ft_printf("not sorted\n");
		sort(&args);
	}
	else
		ft_printf("sorted\n");
	ft_printf("====================PILA=======================\n");
	print_list(args.pila);
	return (free_struct(&args), 0);
}
