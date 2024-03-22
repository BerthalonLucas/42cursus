/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:11:17 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/22 13:11:44 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool sorted(t_args *args)
{
    t_stk *tmp;

    tmp = args->pila;
    while (tmp->next)
    {
        if (tmp->nbr > tmp->next->nbr)
            return (false);
        tmp = tmp->next;
    }
    return (true);
}