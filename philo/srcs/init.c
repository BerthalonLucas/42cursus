/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:28:15 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/09 02:49:00 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void init_struct(t_a *a, int ac, char **av)
{
    memset(a, 0, sizeof(t_a));
    a->gb = (t_gb *)malloc(sizeof(t_gb));
    if (!a->gb)
    {
        ft_putstr_fd("Error: Memory allocation failed\n", 2);
        return;
    }
    a->gb->next = NULL;
    a->nb_philo = ft_atol(av[1]);
    a->time_to_die = ft_atol(av[2]);
    a->time_to_eat = ft_atol(av[3]);
    a->time_to_sleep = ft_atol(av[4]);
    if (ac == 6)
        a->nb_eat = ft_atol(av[5]);
    else
        a->nb_eat = -1;
    a->philo = NULL;
    a->forks = NULL;
}

void init_philosophers(t_a *a)
{
    int i;

    a->philo = new_malloc(a, sizeof(t_philo *) * a->nb_philo);
    if (!a->philo)
        return;
    i = 0;
    while (i < a->nb_philo)
    {
        a->philo[i] = new_malloc(a, sizeof(t_philo));
        if (!a->philo[i])
            return;
        a->philo[i]->id = i;
        a->philo[i]->left = &a->forks[i];
        a->philo[i]->right = &a->forks[(i + 1) % a->nb_philo];
        a->philo[i]->time_to_die = a->time_to_die;
        a->philo[i]->time_to_eat = a->time_to_eat;
        a->philo[i]->time_to_sleep = a->time_to_sleep;
        a->philo[i]->last_time_eat = 0;
        a->philo[i]->has_eat = 0;
        a->philo[i]->nb_eat = a->nb_eat;
        a->philo[i]->time_start = a->time_start;
		a->philo[i]->stop = 0;
		a->philo[i]->print = &a->print[0];
        i++;
    }
}

void	init_mutex(t_a *a)
{
	int	i;

	i = 0;
	a->forks = new_malloc(a, sizeof(pthread_mutex_t) * a->nb_philo);
	a->print = new_malloc(a, sizeof(pthread_mutex_t));
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
	if (pthread_mutex_init(&a->print[0], NULL) != 0)
	{
		ft_putstr_fd("Error initializing mutex\n", 2);
		free_all(a);
		return ;
	}
}
