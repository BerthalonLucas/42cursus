/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 08:31:23 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 08:32:47 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pos(t_args *args)
{
	t_stk	*tmp;
	int		i;

	i = 0;
	if (args->pila)
	{
		tmp = args->pila;
		while (tmp)
		{
			tmp->pos = i;
			i++;
			tmp = tmp->next;
		}
	}
	pos_b(args);
	ft_lst_size(args);
	above_mediane(args);
}

void	pos_b(t_args *args)
{
	t_stk	*tmp;
	int		i;

	i = 0;
	if (args->pilb)
	{
		tmp = args->pilb;
		while (tmp)
		{
			tmp->pos = i;
			i++;
			tmp = tmp->next;
		}
	}
}
