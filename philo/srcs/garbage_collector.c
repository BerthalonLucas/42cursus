/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:31:08 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/08 06:50:45 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *add_to_gb(gb_t *gb, void *ptr)
{
	gb_t *new;

	new = malloc(sizeof(gb_t));
	if (!new)
		return (NULL);
	new->ptr = ptr;
	new->next = gb->next;
	gb->next = new;
	return (ptr);
}

void free_gb(gb_t *gb)
{
	gb_t *tmp;

	while (gb->next)
	{
		tmp = gb->next;
		free(gb->next->ptr);
		gb->next = gb->next->next;
		free(tmp);
	}
}

void *new_malloc(a_t *a, size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		free_gb(a->gb);
		return (NULL);
	}
	add_to_gb(a->gb, ptr);
	return (ptr);
}

void free_all(a_t *a)
{
	free_gb(a->gb);
	free(a->gb);
}
