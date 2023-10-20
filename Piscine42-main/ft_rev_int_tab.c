/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:46:20 by lberthal          #+#    #+#             */
/*   Updated: 2023/08/28 20:22:35 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size -1;
	while (i < size / 2)
	{
		printf("tableau avant : %d %d\n", tab[i], tab[j]);
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		printf("après : %d %d\n", tab[i], tab[j]);
		i++;
		j--;
	}
}

int main(void)
{
	int	b;
	int	table[] = {1, 8, 5, 6, 5, 9, 2, 6, 4};
	b = 9;
	ft_rev_int_tab(table, b);
}
