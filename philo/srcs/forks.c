/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 00:33:29 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/07 00:39:07 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	who_pick_the_fork(t_philo *philo)
{
	if (philo->time_to_die == 0)
	{
		ft_usleep(100);
		return (1);
	}
	if (philo->a->nb_philo == 1)
	{
		one_philo_one_fork(philo);
		return (1);
	}
	if (check_death(philo->a) || check_eat(philo->a))
		return (1);
	take_forks(philo);
	pthread_mutex_lock(philo->a->eat);
	philo->has_eat++;
	pthread_mutex_unlock(philo->a->eat);
	return (0);
}

void	take_forks(t_philo *philo)
{
	if (check_death(philo->a) || check_eat(philo->a))
		return ;
	if (philo->id % 2 == 0 && philo->id != 0)
	{
		pthread_mutex_lock(philo->right);
		print_state(philo, 1);
		philo->has_right = 1;
		pthread_mutex_lock(philo->left);
		print_state(philo, 1);
		philo->has_left = 1;
	}
	else if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->left);
		print_state(philo, 1);
		philo->has_left = 1;
		pthread_mutex_lock(philo->right);
		print_state(philo, 1);
		philo->has_right = 1;
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	philo->has_left = 0;
	pthread_mutex_unlock(philo->right);
	philo->has_right = 0;
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
