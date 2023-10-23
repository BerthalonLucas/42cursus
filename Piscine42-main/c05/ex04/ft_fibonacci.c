/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:21:38 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/18 17:02:25 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_fibonacci(int index)
{
	int	i;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	i = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (i);
}
/*
#include <stdio.h>
int main(void)
{
	int index;

	index = 20;
	printf("%d\n", ft_fibonacci(index));
}*/