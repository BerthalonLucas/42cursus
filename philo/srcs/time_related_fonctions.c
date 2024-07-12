/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_related_fonctions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:36:44 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/12 03:27:34 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	gt(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		ft_putstr_fd("Error: gettimeofday failed\n", 2);
		return (0);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

size_t	cutime(t_a *a)
{
	size_t	current_time;

	current_time = gt() - a->time_start;
	return (current_time);
}

void	ft_usleep(size_t time_in_ms)
{
	size_t	start;

	start = gt();
	while ((gt() - start) < time_in_ms)
		usleep(100);
}
