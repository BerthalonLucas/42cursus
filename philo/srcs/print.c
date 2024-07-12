/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:10:47 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/12 03:25:58 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
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
