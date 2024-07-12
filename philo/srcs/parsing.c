/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:00:02 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/12 01:59:03 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	if (str[0] == '\0')
		return (0);
	while (str[i])
		i++;
	return (i);
}

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
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res > 2147483647)
		return (-1);
	return (res);
}

int	check_value(char **av, int ac)
{
	int		i;
	long	value;

	i = 2;
	while (i < (ac - 1))
	{
		value = ft_atol(av[i]);
		if (value == -1 || value < 60)
			return (0);
		i++;
	}
	return (1);
}

int	valid_start(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("only 5 args needed\n", 2);
		return (1);
	}
	else if (!valid_args(ac, av))
	{
		ft_putstr_fd("only numbers are allowed\n", 2);
		return (1);
	}
	else if (!check_value(av, ac))
	{
		ft_putstr_fd("only autorised value are allowed (>60)\n", 2);
		return (1);
	}
	if (atol(av[1]) < 1 || atol(av[1]) > 200)
	{
		ft_putstr_fd("number of philosophers must be between 1 and 200\n", 2);
		return (1);
	}
	return (0);
}
