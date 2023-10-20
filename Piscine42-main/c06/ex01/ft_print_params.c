/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:02:15 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/18 20:19:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int main(int ac, char **av)
{
	int i;
	int j;

	j = 1;
	if (ac > 4)
		return (0);
	while (j < 4)
	{
		i = 0;
		while (av[j][i])
		{
			write (1, &av[j][i], 1);
			i++;
		}
		j++;
		write (1, "\n", 1);
	}
}