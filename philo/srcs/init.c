/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:28:15 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/08 07:04:28 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void init_struct(a_t *a, int ac, char **av)
{
	int i;

	i = 0;
	memset(a, 0, sizeof(a_t));
	a->gb = malloc(sizeof(gb_t));
	if (!a->gb)
		return ;
}
