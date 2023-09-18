/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:14:27 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/18 01:26:09 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}
/*
#include <stdio.h>
int main(void)
{
	int nb;
	int power;

	nb = 4;
	power = 4;
	printf("%d\n", ft_recursive_power(nb, power));
}*/