/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:53:32 by root              #+#    #+#             */
/*   Updated: 2024/04/09 19:25:29 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	int				nbr;
    int				index;
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

t_stk	*ft_lst_new(t_args *args, int nbr);
t_stk 	*find_last(t_stk *lst);
void 	ft_list_add_back(t_args *args, t_stk *new_lst, char pile);
void	ft_lstclear_pil(t_stk **lst);
void	ft_lst_size(t_args *args);
void	ft_lst_size_b(t_args *args);
bool	ft_is_digit(const char *s);
void	ft_parsing(int ac, char **av);
void	set_index(t_args *args);
bool 	ft_check_double(t_stk *pila);
void	ft_insert(t_args *args, char **av, int ac);
long	ft_atol(char *str);

//================================UTILS================================//

void 	ft_error(t_args *args);
void	free_struct(t_args *args);
void	init_args(t_args *args);
void	init_chain(t_stk *pile, int nbr);
bool	sorted(t_args *args);

//================================OPERATIONS================================//

void	swap_a(t_args *args);
void	swap_b(t_args *args);
void	ss(t_args *args);
void	swap(t_stk **stack);

void	push_a(t_args *args);
void	push_b(t_args *args);
void	push(t_stk **from, t_stk **to);

void	rotate_a(t_args *args);
void	rotate_b(t_args *args);
void    rr(t_args *args);
void	rotate(t_stk **stack);

void	reverse_rotate_a(t_args *args);
void	reverse_rotate_b(t_args *args);
void    rrr(t_args *args);
void	reverse_rotate(t_stk **stack);
void	ops(t_args *args, char *op);

#endif