/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 07:00:38 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/09 01:04:53 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void phtread_create_phi(t_a *a)
{
	int i;
	pthread_t *threads;

	threads = new_malloc(a, sizeof(pthread_t) * a->nb_philo);
	i = 0;
	while (i < a->nb_philo)
	{
		pthread_create(&threads[i], NULL, routine, (void *)a->philo[i]);
		usleep(100);
		i++;
	}
	i = 0;
	while (i < a->nb_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
