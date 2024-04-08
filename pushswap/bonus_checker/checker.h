/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:53:32 by root              #+#    #+#             */
/*   Updated: 2024/04/08 23:55:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_stack
{
	int				nbr;
    int				index;
	int				pos;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stk;

typedef struct	s_args
{
	t_stk		*pila;
	t_stk		*pilb;
	int			lst_size_a;
	int			lst_size_b;
}	t_args;