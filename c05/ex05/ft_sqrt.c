/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:49:36 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/18 01:28:12 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_sqrt(int nb)
{
	int	f;

	f = 1;
	if (nb <= 0)
		return (0);
	while ((f * f) <= nb)
	{
		if (f > 46340)
			return (0);
		else if (f * f == nb)
			return (f);
		f++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	int nb;

	nb = 469225;
	printf("%d\n", ft_sqrt(nb));
}*/
