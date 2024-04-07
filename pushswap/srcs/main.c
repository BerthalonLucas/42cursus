/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:30:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 22:49:07 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_list(t_stk *list)
{
	t_stk	*tmp;

	tmp = list;
	while (tmp)
	{
		ft_printf("nbr [%d] index [%d] cost [%d]\n", tmp->nbr, tmp->index, tmp->push_cost);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_args	args;
	

	if (ac >= 1)
	{
		init_args(&args);
		ft_parsing(ac, av);
		ft_insert(&args, av, ac);
		if (!sorted(&args))
			sort(&args);
		// ft_printf("%d\n", args.tri);
	}
	return (free_struct(&args), 0);
}
