/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:31:08 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/08 08:26:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *add_to_gb(t_gb *gb, void *ptr)
{
	t_gb *new;

	new = malloc(sizeof(t_gb));
	if (!new)
		return (NULL);
	new->ptr = ptr;
	new->next = gb->next;
	gb->next = new;
	return (ptr);
}

void free_gb(t_gb *gb)
{
	t_gb *tmp;

	if (!gb)
		return ;
	while (gb->next)
	{
		tmp = gb->next;
		free(gb->next->ptr);
		gb->next = gb->next->next;
		free(tmp);
	}
}

void *new_malloc(t_a *a, size_t size)
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

void free_all(t_a *a)
{
	free_gb(a->gb);
	if (a->gb)
		free(a->gb);
}
