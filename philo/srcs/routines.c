/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:41:34 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/17 22:39:05 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->stop)
			return (NULL);
		who_pick_the_fork(philo);
		print_state(philo, 2);
		ft_usleep(philo->a->time_to_eat);
		philo->last_time_eat = current_time(philo->time_start);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		print_state(philo, 3);
		ft_usleep(philo->a->time_to_sleep);
		print_state(philo, 0);
	}
}

int print_state(t_philo *philo, int state)
{
	if (state == 0)
	{
		pthread_mutex_lock(philo->a->print);
		printf("[%ld] [%d] is thinking\n", gt() - philo->a->time_start, philo->id);
		pthread_mutex_unlock(philo->a->print);
	}
	else if (state == 1)
	{
		pthread_mutex_lock(philo->a->print);
		printf("[%ld] [%d] has taken a fork\n", gt() - philo->a->time_start, philo->id);
		pthread_mutex_unlock(philo->a->print);
	}
	else if (state == 2)
	{
		pthread_mutex_lock(philo->a->print);
		printf("[%ld] [%d] is eating\n", gt() - philo->a->time_start, philo->id);
		pthread_mutex_unlock(philo->a->print);
	}
	else if (state == 3)
	{
		pthread_mutex_lock(philo->a->print);
		printf("[%ld] [%d] is sleeping\n", gt() - philo->a->time_start, philo->id);
		pthread_mutex_unlock(philo->a->print);
	}
	else if (state == 4)
	{
		pthread_mutex_lock(philo->a->print);
		printf("[%ld] [%d] died\n", gt() - philo->a->time_start, philo->id);
		pthread_mutex_unlock(philo->a->print);
	}
	return (0);
}
void *monitoring(void *arg)
{
	t_a *a;
	int i;
	size_t time;

	a = (t_a *)arg;
	while (1)
	{
		i = 0;
		while (i < a->nb_philo)
		{
			if (a->philo[i]->last_time_eat > (size_t)a->time_to_die)
			{
				print_state(a->philo[i], 4);
				a->stop = 1;
				pthread_mutex_lock(a->philo[i]->a->stop_m);
				a->philo[i]->stop = 1;
				pthread_mutex_unlock(a->philo[i]->a->stop_m);
				return (NULL);
			}
		}
		if (a->stop)
			return (NULL);
	}
}

int who_pick_the_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right);
		print_state(philo, 1);
		pthread_mutex_lock(philo->left);
		print_state(philo, 1);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		print_state(philo, 1);
		pthread_mutex_lock(philo->right);
		print_state(philo, 1);
	}
	return (0);
}
