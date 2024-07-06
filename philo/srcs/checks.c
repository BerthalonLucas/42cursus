/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 00:32:28 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/04 00:32:45 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_death(t_a *a)
{
	int	stop;

	pthread_mutex_lock(a->stop_m);
	stop = a->stop;
	pthread_mutex_unlock(a->stop_m);
	if (stop == 1)
		return (1);
	else
		return (0);
	return (0);
}

int	check_eat(t_a *a)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < a->nb_philo && a->nb_eat != -1)
	{
		if (a->philo[i]->has_eat >= a->nb_eat)
			count++;
		i++;
	}
	if (count == a->nb_philo && a->nb_eat != -1)
	{
		a->stop = 1;
		return (1);
	}
	return (0);
}
