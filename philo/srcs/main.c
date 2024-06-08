/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:08:52 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/08 06:27:42 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int ac, char **av)
{
	a_t    a;

	(void)a;
	if (valid_start(ac, av))
		return (1);
	init_struct(&a, ac, av);
		return (0);
}
