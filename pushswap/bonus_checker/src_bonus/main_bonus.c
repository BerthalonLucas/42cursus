/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:14:33 by root              #+#    #+#             */
/*   Updated: 2024/04/09 20:09:00 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

bool	sorted(t_args *args)
{
	t_stk	*tmp;

	tmp = args->pila;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (false);
		tmp = tmp->next;
	}
	if (args->pilb)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	char	*s;
	t_args	args;

	if (ac == 1)
		return (0);
	ft_parsing(ac, av);
	init_args(&args);
	ft_insert(&args, av, ac);
	while (42)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		ops(&args, s);
	}
	if (sorted(&args))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (free_struct(&args), 0);
}
