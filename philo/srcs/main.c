/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:08:52 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/17 21:43:26 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_a	a;

	if (valid_start(ac, av))
		return (1);
	init_struct(&a, ac, av);
	init_mutex(&a);
	init_philosophers(&a);
	a.time_start = gt();
	put_time(&a);
	phtread_create_phi(&a);
	int i = 0;
	while (i < a.nb_philo)
	{
		pthread_mutex_destroy(&a.forks[i]);
		i++;
	}
	pthread_mutex_destroy(a.print);
	pthread_mutex_destroy(a.stop_m);
	free_all(&a);
	return (0);
}

