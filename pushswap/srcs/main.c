/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:30:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/01 21:38:56 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	t_stk *tmp = args.pila;
	while (tmp)
	{
		ft_printf("sorted numbers : [%d] Indexs [%d]\n", tmp->nbr, tmp->index);
		tmp = tmp->next;
	}
	return (free_struct(&args), 0);
}
