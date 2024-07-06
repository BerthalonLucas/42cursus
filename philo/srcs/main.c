/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:08:52 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/07 00:59:54 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_struct_philo(t_a *a)
{
	int	i;

	i = 0;
	while (i < a->nb_philo)
	{
		printf("philo [%d]\n", a->philo[i]->id);
		printf("has_eaten [%d]\n", a->philo[i]->has_eat);
		printf("nb_eat [%d]\n", a->philo[i]->nb_eat);
		printf("last_time_eat [%d]\n", a->philo[i]->last_time_eat);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_a	a;

	if (valid_start(ac, av))
		return (1);
	init_struct(&a, ac, av);
	init_mutex(&a);
	a.time_start = gt();
	init_philosophers(&a);
	pthread_create_phi(&a);
	destroy_mutex(&a);
	all_philo_eat(&a);
	free_all(&a);
	return (0);
}
