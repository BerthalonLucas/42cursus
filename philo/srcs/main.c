/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:08:52 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/08 08:34:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int main(int ac, char **av)
// {
// 	t_a    a;

// 	(void)a;
// 	if (valid_start(ac, av))
// 		return (1);
// 	init_struct(&a, ac, av);
// 		return (0);
// }

void	print_philosophers(t_a *a)
{
	int	i;

	i = 0;
	while (i < a->nb_philo)
	{
		printf("Philosopher %d: left fork = %p, right fork = %p\n",
			a->philo[i]->id, (void *)a->philo[i]->left, (void *)a->philo[i]->right);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_a	a;

	if (valid_start(ac, av))
		return (1);
	init_struct(&a, ac, av);
	init_mutex(&a);
	init_philosophers(&a);
	print_philosophers(&a);

	// Nettoyage
	for (int i = 0; i < a.nb_philo; i++)
		pthread_mutex_destroy(&a.forks[i]);
	free_all(&a);
	return (0);
}

