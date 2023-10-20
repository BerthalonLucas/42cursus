/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:35:06 by lberthal          #+#    #+#             */
/*   Updated: 2023/08/27 14:36:08 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writer(int nb0, int nb1)
{
	char	d1;
	char	u1;
	char	d0;
	char	u0;

	if (nb0 != 98)
	{
		d0 = nb0 / 10 + 48;
		u0 = nb0 % 10 + 48;
		d1 = nb1 / 10 + 48;
		u1 = nb1 % 10 + 48;
		write (1, &d0, 1);
		write (1, &u0, 1);
		write (1, " ", 1);
		write (1, &d1, 1);
		write (1, &u1, 1);
		write (1, ", ", 2);
	}
	else
	{
		write (1, "98 99", 5);
	}
}

void	ft_print_comb2(void)
{
	int	nb0;
	int	nb1;

	nb0 = 0;
	while (nb0 <= 98)
	{
		nb1 = nb0 + 1;
		while (nb1 <= 99)
		{
			writer(nb0, nb1);
			nb1++;
		}
		nb0++;
	}
}
