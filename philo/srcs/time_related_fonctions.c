/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_related_fonctions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:36:44 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/17 22:24:08 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"

size_t gt(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		exit(EXIT_FAILURE);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

size_t current_time(size_t time)
{
	size_t current_time;

	current_time = gt() - time;
	return (current_time);
}

void put_time(t_a *a)
{
	int i;

	i = 0;
	while (i < a->nb_philo)
	{
		a->philo[i]->time_start = a->time_start;
		i++;
	}
}

void ft_usleep(size_t time_in_ms)
{
	size_t start;

	start = gt();
	while ((gt() - start) < time_in_ms)
		usleep(100);
}
