/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:28:15 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/04 22:34:18 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_struct(t_a *a, int ac, char **av)
{
	memset(a, 0, sizeof(t_a));
	a->gb = (t_gb *)malloc(sizeof(t_gb));
	if (!a->gb)
	{
		ft_putstr_fd("Error: Memory garbage allocation failed\n", 2);
		return ;
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
	a->stop = 0;
	a->philo = NULL;
	a->forks = NULL;
	a->print = NULL;
	a->monitor = NULL;
	a->stop_m = NULL;
}

void	init_philosophers(t_a *a)
{
	int	i;

	a->philo = new_malloc(a, sizeof(t_philo *) * a->nb_philo);
	if (!a->philo)
		return ;
	i = 0;
	init_phi_2(a, i);
}

void	init_phi_2(t_a *a, int i)
{
	while (i < a->nb_philo)
	{
		a->philo[i] = new_malloc(a, sizeof(t_philo));
		if (!a->philo[i])
			return ;
		a->philo[i]->id = i;
		a->philo[i]->left = &a->forks[i];
		if (a->nb_philo == 1)
			a->philo[i]->right = &a->forks[i];
		else
			a->philo[i]->right = &a->forks[(i + 1) % a->nb_philo];
		a->philo[i]->time_to_die = a->time_to_die;
		a->philo[i]->time_to_eat = a->time_to_eat;
		a->philo[i]->time_to_sleep = a->time_to_sleep;
		a->philo[i]->last_time_eat = 0;
		a->philo[i]->has_eat = 0;
		a->philo[i]->nb_eat = a->nb_eat;
		a->philo[i]->time_start = a->time_start;
		a->philo[i]->stop = 0;
		a->philo[i]->a = a;
		a->philo[i]->has_left = 0;
		a->philo[i]->has_right = 0;
		i++;
	}
}
