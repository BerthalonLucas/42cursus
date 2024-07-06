/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:02:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/04 00:31:54 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_mutex(t_a *a)
{
	int	i;

	i = 0;
	a->forks = new_malloc(a, sizeof(pthread_mutex_t) * a->nb_philo);
	a->print = new_malloc(a, sizeof(pthread_mutex_t));
	a->stop_m = new_malloc(a, sizeof(pthread_mutex_t));
	a->eat = new_malloc(a, sizeof(pthread_mutex_t));
	if (!a->forks || !a->print)
	{
		free_all(a);
		return ;
	}
	while (i < a->nb_philo)
	{
		if (pthread_mutex_init(&a->forks[i], NULL) != 0)
		{
			ft_putstr_fd("Error initializing mutex\n", 2);
			free_all(a);
			return ;
		}
		i++;
	}
	init_mutex_2(a);
}

void	init_mutex_2(t_a *a)
{
	if (pthread_mutex_init(a->print, NULL) != 0)
	{
		ft_putstr_fd("Error initialize mutex print\n", 2);
		free_all(a);
		return ;
	}
	if (pthread_mutex_init(a->stop_m, NULL) != 0)
	{
		ft_putstr_fd("Error initialize mutex stop\n", 2);
		free_all(a);
		return ;
	}
	if (pthread_mutex_init(a->eat, NULL) != 0)
	{
		ft_putstr_fd("Error initialize mutex eat\n", 2);
		free_all(a);
		return ;
	}
}

void	destroy_mutex(t_a *a)
{
	int	i;

	i = 0;
	while (i < a->nb_philo)
	{
		pthread_mutex_destroy(&a->forks[i]);
		i++;
	}
	pthread_mutex_destroy(a->print);
	pthread_mutex_destroy(a->stop_m);
	pthread_mutex_destroy(a->eat);
}
