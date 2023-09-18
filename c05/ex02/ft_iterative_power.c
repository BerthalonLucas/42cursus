/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:59:03 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/18 01:27:55 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	f;

	i = power;
	f = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	while (i > 1)
	{
		nb = nb * f;
		i--;
	}
	return (nb);
}
/*
#include <stdio.h>
int main(void)
{
	int nb;
	int power;

	nb = 9;
	power = 1;
	printf("%d\n", ft_iterative_power(nb, power));
}*/