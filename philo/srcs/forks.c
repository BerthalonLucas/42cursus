/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 00:33:29 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/12 03:26:44 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	who_pick_the_fork(t_philo *philo)
{
	if (philo->a->nb_philo == 1)
	{
		one_philo_one_fork(philo);
		return (1);
	}
	if (check_death(philo->a) || check_eat(philo->a))
		return (1);
	if (take_forks(philo))
		return (1);
	pthread_mutex_lock(philo->a->eat);
	philo->has_eat++;
	pthread_mutex_unlock(philo->a->eat);
	if (print_state(philo, 2))
		return (1);
	ft_usleep(philo->time_to_eat);
	release_forks(philo);
	pthread_mutex_lock(philo->a->lte);
	philo->last_time_eat = cutime(philo->a);
	pthread_mutex_unlock(philo->a->lte);
	if (print_state(philo, 3))
		return (1);
	ft_usleep(philo->time_to_sleep);
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (check_death(philo->a) || check_eat(philo->a))
		return (1);
	pthread_mutex_lock(philo->left);
	print_state(philo, 1);
	philo->has_left = 1;
	pthread_mutex_lock(philo->right);
	print_state(philo, 1);
	philo->has_right = 1;
	return (0);
}

void	release_forks(t_philo *philo)
{
	if (philo->has_left)
	{
		pthread_mutex_unlock(philo->left);
		philo->has_left = 0;
	}
	if (philo->has_right)
	{
		pthread_mutex_unlock(philo->right);
		philo->has_right = 0;
	}
}

void	*getback(t_philo *philo)
{
	if (philo->has_left)
		pthread_mutex_unlock(philo->left);
	if (philo->has_right)
		pthread_mutex_unlock(philo->right);
	return (NULL);
}

void	one_philo_one_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_state(philo, 1);
	ft_usleep(philo->time_to_die - 100);
	pthread_mutex_unlock(philo->left);
}
