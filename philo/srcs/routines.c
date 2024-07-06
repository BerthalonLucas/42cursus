/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:41:34 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/06 02:55:02 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(10);
	while (1)
	{
		if (philo->a->stop)
			return (getback(philo));
		if (who_pick_the_fork(philo))
			return (getback(philo));
		philo->last_time_eat = cutime(philo->a);
		if (print_state(philo, 2))
			return (getback(philo));
		ft_usleep(philo->time_to_eat);
		release_forks(philo);
		if (print_state(philo, 3))
			return (getback(philo));
		ft_usleep(philo->time_to_sleep);
		if (print_state(philo, 0))
			return (getback(philo));
		if (philo->has_eat >= philo->nb_eat && philo->nb_eat != -1)
			return (getback(philo));
	}
	return (getback(philo));
}

int	print_state(t_philo *philo, int state)
{
	if (state == 0)
	{
		if (check_death(philo->a) || check_eat(philo->a))
			return (1);
		pthread_mutex_lock(philo->a->print);
		printf("%ld %d is thinking\n", cutime(philo->a), philo->id);
		pthread_mutex_unlock(philo->a->print);
	}
	else if (state == 1)
	{
		if (check_death(philo->a) || check_eat(philo->a))
			return (1);
		pthread_mutex_lock(philo->a->print);
		printf("%ld %d has taken a fork\n", cutime(philo->a), philo->id);
		pthread_mutex_unlock(philo->a->print);
	}
	return (print_state_2(philo, state));
}

int	print_state_2(t_philo *philo, int state)
{
	if (state == 2)
	{
		if (check_death(philo->a) || check_eat(philo->a))
			return (1);
		pthread_mutex_lock(philo->a->print);
		printf("%ld %d is eating\n", cutime(philo->a), philo->id);
		pthread_mutex_unlock(philo->a->print);
	}
	else if (state == 3)
	{
		if (check_death(philo->a) || check_eat(philo->a))
			return (1);
		pthread_mutex_lock(philo->a->print);
		printf("%ld %d is sleeping\n", cutime(philo->a), philo->id);
		pthread_mutex_unlock(philo->a->print);
	}
	else if (state == 4)
	{
		if (check_death(philo->a) || check_eat(philo->a))
			return (1);
		pthread_mutex_lock(philo->a->print);
		printf("%ld %d died\n", cutime(philo->a), philo->id);
		pthread_mutex_unlock(philo->a->print);
	}
	return (0);
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
		while (i < a->nb_philo)
		{
			if (a->nb_eat != -1 && check_eat(a))
				return (NULL);
			if (a->stop)
				return (NULL);
			if ((cutime(a)
					- a->philo[i]->last_time_eat) > (size_t)a->time_to_die)
			{
				print_state(a->philo[i], 4);
				a->stop = 1;
				pthread_mutex_lock(a->philo[i]->a->stop_m);
				a->philo[i]->stop = 1;
				pthread_mutex_unlock(a->philo[i]->a->stop_m);
				return (NULL);
			}
			i++;
		}
		if (a->stop)
			return (NULL);
	}
}
