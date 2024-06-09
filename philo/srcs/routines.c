/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:41:34 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/09 03:44:48 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *routine(void *arg)
{
	t_philo *philo;
	long long time_since_last_meal;

	philo = (t_philo *)arg;
	while (1)
	{
		print_struct_philo_alone(philo);
		printf("[%d] Philosopher [%d] is thinking\n", current_time(philo), philo->id);
		pthread_mutex_lock(philo->left);
		printf("[%d] Philosopher [%d] has taken a fork\n", current_time(philo), philo->id);
		pthread_mutex_lock(philo->right);
		printf("[%d] Philosopher [%d] has taken a fork\n", current_time(philo), philo->id);
		philo->last_time_eat = gt();
		philo->has_eat++;
		printf("[%d] Philosopher [%d] is eating\n", current_time(philo), philo->id);
		ft_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		printf("[%d] Philosopher [%d] is sleeping\n", current_time(philo), philo->id);
		ft_usleep(philo->time_to_sleep);
		if (philo->has_eat == philo->nb_eat)
			break;
		time_since_last_meal = gt() - philo->last_time_eat;
		if (time_since_last_meal > philo->time_to_die)
		{
			printf("[%d] Philosopher [%d] died\n", current_time(philo), philo->id);
			philo->stop = 1;
			break;
		}
	}
	return (NULL);
}

int current_time(t_philo *philo)
{
	int time;

	time = ct(philo->time_start);
	return (time);
}


