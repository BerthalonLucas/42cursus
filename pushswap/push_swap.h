/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:56:21 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/05 20:23:03 by lberthal         ###   ########.fr       */
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
	int				pos;
	int				push_cost;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	bool			above_mediane;
	struct s_stack	*target;
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

//================================LIST================================//

t_stk	*ft_lst_new(t_args *args, int nbr);
t_stk 	*find_last(t_stk *lst);
void 	ft_list_add_back(t_args *args, t_stk *new, char pile);
void	ft_lstclear_pil(t_stk **lst);
void	ft_lst_size(t_args *args);
void	ft_lst_size_b(t_args *args);

//================================PARSING================================//

bool	ft_is_digit(const char *s);
void	ft_parsing(int ac, char **av);
void	set_index(t_args *args);
bool 	ft_check_double(t_stk *pila);
void	ft_insert(t_args *args, char **av, int ac);
long	ft_atol(char *str);

//================================UTILS================================//

void 	ft_error(t_args *args, char *error);
void	free_struct(t_args *args);
void	init_args(t_args *args);
void	init_chain(t_stk *pile, int nbr);

//================================OPERATIONS================================//
void	swap_a(t_args *args);
void	swap_b(t_args *args);
void	ss(t_args *args);
void	swap(t_stk **stack);

void	push_a(t_args *args);
void	push_b(t_args *args);
void	first_push_b(t_args *args);
void	push(t_stk **from, t_stk **to);

void	rotate_a(t_args *args);
void	rotate_b(t_args *args);
void    rr(t_args *args);
void	rotate(t_stk **stack);

void	reverse_rotate_a(t_args *args);
void	reverse_rotate_b(t_args *args);
void    rrr(t_args *args);
void	reverse_rotate(t_stk **stack);

//================================ALGO================================//

void	sort(t_args *args);
void 	sort_three(t_args *args);
void	sort_four(t_args *args);
void	sort_five(t_args *args);
void	sort_big(t_args *args);
void	do_ops(t_args *args);
void	do_rr_and_rrr(t_args *args, t_stk *cheapest);
void 	do_ra_and_rra(t_args *args, t_stk *cheapest);
void	do_rb_and_rrb(t_args *args, t_stk *cheapest);



//=============================AGLO_UTILS============================//

void 	push_cost(t_args *args);
void	push_cost_above(t_stk *tmpb);
void	push_cost_bellow(t_args *args, t_stk *tmpb);
void	push_cost_else(t_args *args, t_stk *tmpb);
void	pos(t_args *args);
void	pos_b(t_args *args);
void	above_mediane(t_args *args);
void	above_mediane_b(t_args *args);
void	reset_ops(t_args *args);
void	find_target(t_args *args);
t_stk	*find_smallest(t_args *args);
t_stk	*find_biggest(t_args *args);
t_stk	*find_cheapest(t_stk *tmpb);
void	iter_index(t_args *args);
void	final_sort(t_args *args, int pos, bool mediane);
t_stk	*find_neerest_bigger(t_args *args, int number);
bool 	sorted(t_args *args);

// void print_list(t_stk *list);



#endif