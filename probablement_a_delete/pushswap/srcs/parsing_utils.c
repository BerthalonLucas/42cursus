/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:14:35 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/11 02:25:19 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_maxmin(long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

long	ft_atol(char *str)
{
	int		i;
	long	sign;
	long	res;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		check_maxmin(res * sign);
		i++;
	}
	return (res * sign);
}
