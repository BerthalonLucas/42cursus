/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:56:21 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/16 02:18:08 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"


typedef struct s_stack
{
	int				nbr;
    int				index;
	int				push_cost;
	bool			above_mediane;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stk;

typedef struct	s_args
{
	t_stk		*pila;
	t_stk		*pilb;
}	t_args;

void	free_struct(t_args *args);
t_stk	*ft_lst_new(t_args *args, int nbr);
t_stk *find_last(t_stk *lst);
void ft_list_add_back(t_args *args, t_stk *new, char pile);
void	ft_lstclear_pil(t_stk *lst);
void	init_args(t_args *args);

#endif