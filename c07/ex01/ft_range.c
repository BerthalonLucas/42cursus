/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:08:14 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/21 19:43:28 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
	int i;
	int *tab;

	i = 0;
	tab = malloc(sizeof(*tab) * (max - min));
	if (!tab)
		return (NULL);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}

int main(void)
{
	int *tab;
	int i;
	int f;
	int j;

	j = -8;
	f = 15;
	tab = ft_range(j, f);
	i = 0;
	while (tab[i])
	{
		printf("%d, ", tab[i]);
		if (tab[i] == - 1)
		{
			printf("0, ");
			i++;
		}
		i++;
	}
	printf("\n");
	free (ft_range(j, f));
}