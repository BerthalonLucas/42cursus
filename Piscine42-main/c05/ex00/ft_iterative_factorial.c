/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:59:56 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/18 17:03:18 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb - 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	while (i != 1)
	{
		nb = nb * i;
		i--;
	}
	return (nb);
}
/*
#include <stdio.h>
int main(void)
{
    int nb;

    nb = 1;
    printf("%d\n", ft_iterative_factorial(nb));
}*/
