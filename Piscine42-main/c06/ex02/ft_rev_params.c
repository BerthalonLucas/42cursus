/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:19:33 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/18 20:43:54 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int main(int ac, char **av)
{
	int i;

	ac = ac - 1;
	if (ac > 4)
		return (0);
	while (ac > 0)
	{
		i = 0;
		while (av[ac][i])
		{
			write (1, &av[ac][i], 1);
			i++;
		}
		ac--;
		write (1, "\n", 1);
	}
}