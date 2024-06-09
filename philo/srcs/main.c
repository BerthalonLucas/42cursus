/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:08:52 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/09 02:57:26 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	print_philosophers(t_a *a)
// {
// 	int	i;

// 	i = 0;
// 	while (i < a->nb_philo)
// 	{
// 		printf("Philosopher [%d]: gauche [%p], droite = [%p]}\n",
// 			a->philo[i]->id, (void *)a->philo[i]->left, (void *)a->philo[i]->right);
// 		i++;
// 	}
// }

void print_struct_philo(t_a *a)
{
	int i = 0;
	while (i < a->nb_philo)
	{
		printf("id = %d\n", a->philo[i]->id);
		printf("stop = %d\n", a->philo[i]->stop);
		printf("time_to_die = %d\n", a->philo[i]->time_to_die);
		printf("time_to_sleep = %d\n", a->philo[i]->time_to_sleep);
		printf("time_to_eat = %d\n", a->philo[i]->time_to_eat);
		printf("last_time_eat = %d\n", a->philo[i]->last_time_eat);
		printf("time_start = %lld\n", a->philo[i]->time_start);
		printf("has_eat = %d\n", a->philo[i]->has_eat);
		printf("nb_eat = %d\n", a->philo[i]->nb_eat);
		printf("left = %p\n", (void *)a->philo[i]->left);
		printf("right = %p\n", (void *)a->philo[i]->right);
		i++;
	}
}

void print_struct_a(t_a *a)
{
	printf("nb_philo = %d\n", a->nb_philo);
	printf("time_to_die = %d\n", a->time_to_die);
	printf("time_to_eat = %d\n", a->time_to_eat);
	printf("time_to_sleep = %d\n", a->time_to_sleep);
	printf("nb_eat = %d\n", a->nb_eat);
	printf("time_start = %lld\n", a->time_start);
	printf("philo = %p\n", (void *)a->philo);
	printf("gb = %p\n", (void *)a->gb);
	printf("forks = %p\n", (void *)a->forks);
}
void print_struct_philo_alone(t_philo *philo)
{
	printf("id = %d\n", philo->id);
	printf("stop = %d\n", philo->stop);
	printf("time_to_die = %d\n", philo->time_to_die);
	printf("time_to_sleep = %d\n", philo->time_to_sleep);
	printf("time_to_eat = %d\n", philo->time_to_eat);
	printf("last_time_eat = %d\n", philo->last_time_eat);
	printf("time_start = %lld\n", philo->time_start);
	printf("has_eat = %d\n", philo->has_eat);
	printf("nb_eat = %d\n", philo->nb_eat);
	printf("left = %p\n", (void *)philo->left);
	printf("right = %p\n", (void *)philo->right);
}

int	main(int ac, char **av)
{
	t_a	a;

	if (valid_start(ac, av))
		return (1);
	init_struct(&a, ac, av);
	init_mutex(&a);
	init_philosophers(&a);
	a.time_start = gt();
	put_time(&a);
	// print_struct_philo(&a);
	// print_struct_a(&a);
	printf("time start = %lld\n", a.time_start);
	phtread_create_phi(&a);
	int i = 0;
	while (i < a.nb_philo)
	{
		pthread_mutex_destroy(&a.forks[i]);
		i++;
	}
	pthread_mutex_destroy(a.print);
	free_all(&a);
	return (0);
}

