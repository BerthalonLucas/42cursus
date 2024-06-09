/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_related_fonctions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:36:44 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/09 03:44:06 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"

long long gt(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
}

long long ct(long long time)
{
	return (gt() - time);
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

void ft_usleep(long long time_in_ms)
{
	struct timeval start;
	struct timeval current;
	long long start_time;
	long long current_time;

	gettimeofday(&start, NULL);
	start_time = start.tv_sec * 1000LL + start.tv_usec / 1000LL;

	while (1)
	{
		gettimeofday(&current, NULL);
		current_time = current.tv_sec * 1000LL + current.tv_usec / 1000LL;
		if (current_time - start_time >= time_in_ms)
			break;
	}
}
