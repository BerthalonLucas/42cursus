/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:30:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/08 23:28:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	}
	return (free_struct(&args), 0);
}
