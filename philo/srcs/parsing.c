/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:00:02 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/07 01:00:26 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	valid_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int	i;
	long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	valid_start(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("only 5 args needed\n", 2);
		return (1);
	}
	if (!valid_args(ac, av))
	{
		ft_putstr_fd("only numbers are allowed\n", 2);
		return (1);
	}
	if (atol(av[1]) < 1 || atol(av[1]) > 200)
	{
		ft_putstr_fd("number of philosophers must be between 1 and 200\n", 2);
		return (1);
	}
	return (0);
}
