/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:30:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/22 15:02:33 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_args	args;

	init_args(&args);
	ft_printf("test1\n");
	ft_parsing(ac, av);
	ft_insert(&args, av, ac);
	ft_printf("test2\n");
	if (!sorted(&args))
	{
		ft_printf("not sorted\n");
		sort(&args);
	}	
	ft_printf("test3\n");
	return (free_struct(&args), 0);
}
