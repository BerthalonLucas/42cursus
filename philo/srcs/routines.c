/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:41:34 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/12 03:25:39 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->a->time_to_eat);
	while (1)
	{
		if (philo->a->stop)
			return (getback(philo));
		if (who_pick_the_fork(philo))
			return (getback(philo));
		if (print_state(philo, 0))
			return (getback(philo));
		if (philo->has_eat >= philo->nb_eat && philo->nb_eat != -1)
			return (getback(philo));
	}
	return (getback(philo));
}

void	*monitoring(void *arg)
{
	t_a	*a;
	int	i;

	a = (t_a *)arg;
	i = 0;
	return (monitoring_2(a, i));
}

void	*monitoring_2(t_a *a, int i)
{
	while (1)
	{
		i = 0;
		if (monitoring_3(a, i))
			return (NULL);
		if (a->stop)
			return (NULL);
	}
}

int	monitoring_3(t_a *a, int i)
{
	while (i < a->nb_philo)
	{
		if (a->nb_eat != -1 && check_eat(a))
			return (1);
		if (a->stop)
			return (1);
		pthread_mutex_lock(a->lte);
		if ((cutime(a) - a->philo[i]->last_time_eat) > (size_t)a->time_to_die)
		{
			pthread_mutex_unlock(a->lte);
			print_state(a->philo[i], 4);
			a->stop = 1;
			pthread_mutex_lock(a->philo[i]->a->stop_m);
			a->philo[i]->stop = 1;
			pthread_mutex_unlock(a->philo[i]->a->stop_m);
			return (1);
		}
		pthread_mutex_unlock(a->lte);
		i++;
	}
	return (0);
}
