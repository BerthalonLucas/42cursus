/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:55:26 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 09:02:25 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lst_size(t_args *args)
{
	t_stk	*tmpa;
	int		i;

	i = 0;
	tmpa = args->pila;
	if (tmpa)
	{
		tmpa = args->pila;
		while (tmpa)
		{
			i++;
			tmpa = tmpa->next;
		}
		args->lst_size_a = i;
	}
	else
		args->lst_size_a = 0;
	ft_lst_size_b(args);
}

void	ft_lst_size_b(t_args *args)
{
	t_stk	*tmpb;
	int		i;

	i = 0;
	tmpb = args->pilb;
	if (tmpb)
	{
		tmpb = args->pilb;
		while (tmpb)
		{
			i++;
			tmpb = tmpb->next;
		}
		args->lst_size_b = i;
	}
	else
		args->lst_size_b = 0;
}
