/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:03:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/22 15:16:28 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stk *stack)
{
	t_stk	*first;
	t_stk	*last;

	if (stack && stack->next)
	{
		first = stack;
		stack = stack->next;
		stack->prev = NULL;
		last = stack;
		while (last->next != NULL)
			last = last->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
}
void rotate_a(t_args *args)
{
    ft_printf("ra\n");
    rotate(args->pila);
}

void rotate_b(t_args *args)
{
    ft_printf("rb\n");
    rotate(args->pilb);
}
void rr(t_args *args)
{
    ft_printf("rr\n");
    rotate(args->pila);
    rotate(args->pilb);
}
void	reverse_rotate(t_stk *stack)
{
	t_stk	*last;
	t_stk	*before_last;
	
	if (stack && stack->next)
	{
		last = stack;
		while (last->next != NULL)
			last = last->next;
		before_last = last->prev;
		before_last->next = NULL;
		last->prev = NULL;
		last->next = stack;
		stack->prev = last;
		stack = last;
	}
}
void reverse_rotate_a(t_args *args)
{
    ft_printf("rra\n");
    reverse_rotate(args->pila);
}
void reverse_rotate_b(t_args *args)
{
    ft_printf("rrb\n");
    reverse_rotate(args->pilb);
}
void rrr(t_args *args)
{
    ft_printf("rrr\n");
    reverse_rotate(args->pila);
    reverse_rotate(args->pilb);
}
void	push(t_args *args, t_stk *from, t_stk *to)
{
	t_stk	*first;

	if (from)
	{
		first = from;
		from = from->next;
		if (from)
			from->prev = NULL;
		if (!to)
		{
			ft_list_add_back(args, to, 'b');
			first->next = to;
		}
		if (to)
			to->prev = first;
		to = first;

	}
}
void push_a(t_args *args)
{
    ft_printf("pa\n");
    push(args, args->pilb, args->pila);
}

void push_b(t_args *args)
{
    ft_printf("pb\n");
    push(args, args->pila, args->pilb);
}
void	swap(t_stk *stack)
{
	t_stk	*first;
	t_stk	*second;

	if (stack && stack->next)
	{
		first = stack;
		second = first->next;
		first->next = second->next;
		if (second->next != NULL)
			second->next->prev = first;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
		stack = second;
	}
}
void swap_a(t_args *args)
{
    ft_printf("sa\n");
    swap(args->pila);
}
void swap_b(t_args *args)
{
    ft_printf("sb\n");
    swap(args->pilb);
}
void ss(t_args *args)
{
    ft_printf("ss\n");
    swap(args->pila);
    swap(args->pilb);
}
t_stk	*ft_lst_new(t_args *args, int nbr)
{
	t_stk	*new;

	new = malloc(sizeof(t_stk));
	if (!new)
		ft_error(args, "Malloc failed");
	init_chain(new, nbr);
	return (new);
}

t_stk *find_last(t_stk *lst)
{
	t_stk	*temp;

	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
void ft_list_add_back(t_args *args, t_stk *new, char pile)
{
	t_stk *last;

	if (pile == 'a')
	{
		if(!args->pila)
			args->pila = new;
		else
		{
			last = find_last(args->pila);
			last->next = new;
			new->prev = last;
		}
	}
	else
	{
		if(!args->pilb)
			args->pilb = new;
		else
		{
			last = find_last(args->pilb);
			last->next = new;
			new->prev = last;
		}
	}	
}

void	ft_lstclear_pil(t_stk *lst)
{
	t_stk	*temp;
	t_stk	*next;

	if (!lst)
		return ;
	temp = lst;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	lst = NULL;
}
int	ft_lst_size(t_stk *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
void	init_args(t_args *args)
{
	args->pila = NULL;
	args->pilb = NULL;
}
void init_chain(t_stk *pile, int nbr)
{
	pile->next = NULL;
	pile->prev = NULL;
	pile->target = NULL;
	pile->nbr = nbr;
	pile->index = 0;
	pile->size = 0;
	pile->push_cost = 0;
	pile->above_mediane = false;
	pile->cheapest = false;
}
void	set_index(t_stk *pila)
{
	int size;
	t_stk *lst;
	t_stk *pmax;
	int max;
	
	size = ft_lst_size(pila);
	while (size--, size > 0)
	{
		lst = pila;
		max = INT_MIN;
		pmax = NULL;
		while (lst != NULL)
		{
			if (lst->index == 0 && lst->nbr > max) 
			{
				max = lst->nbr;
				pmax = lst;
			}
			lst = lst->next;
		}
		if (pmax != NULL)
			pmax->index = size;
	}
}

bool ft_check_double(t_stk *pila)
{
	t_stk *actuel;
	t_stk *comp;
	
	actuel = pila;
	while (actuel != NULL)
	{
		comp = actuel->next;
		while (comp != NULL)
		{
			if (actuel->nbr == comp->nbr) 
				return true;
			comp = comp->next;
		}
		actuel = actuel->next;
	}
	return false;
}

void	ft_insert(t_args *args, char **av, int ac)
{
	int i;
	long value;
	
	i = 1;
	while (i < ac)
	{
		value = atol(av[i]);
		ft_list_add_back(args, ft_lst_new(args, value), 'a');
		i++;
	}
	if (ft_check_double(args->pila))
		ft_error(args, "invalid input (insert)");
	set_index(args->pila);
}
bool	ft_is_digit(const char *s)
{
	int	i;

	i = -1;
	if (!s)
		return false;
	if (*s == '-')
		i++;
	while (i++, s[i] >= '0' && s[i] <= '9');
	if ((int)ft_strlen(s) != i)
		return false;
	return true;
}
void	ft_parsing(int ac, char **av)
{

	int i;
	long y;

	i = 1;
	while (i < ac)
	{
		y = ft_atol(av[i]);
		if (!ft_is_digit(av[i]))
			ft_error(NULL, "invalid input (parsing)");
		if (y > INT_MAX || y < INT_MIN)
			ft_error(NULL, "invalid input (parsing)");
		i++;
	}
}
void sort(t_args *args)
{
	int	size;

	size = ft_lst_size(args->pila);
	if (size == 2)
	{
		if (args->pila->nbr > args->pila->next->nbr)
			swap_a(args);
	}
	else if (size == 3)
		sort_three(args);
	else if (size == 5)
		sort_five(args);
	else
		sort_big(args);
}
void sort_three(t_args *args)
{
	int a;
	int b;
	int c;

	a = args->pila->nbr;
	b = args->pila->next->nbr;
	c = args->pila->next->next->nbr;
	if (a > b && b < c && a < c)
		swap_a(args);
	else if (a > b && b > c)
	{
		swap_a(args);
		reverse_rotate_a(args);
	}
	else if (a > b && b < c && a > c)
		rotate_a(args);
	else if (a < b && b > c && a < c)
	{
		swap_a(args);
		rotate_a(args);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(args);
}
void sort_five(t_args *args)
{
	int i;
	int min;
	int max;
	t_stk *lst;
	
	i = 0;
	while (i < 2)
	{
		lst = args->pila;
		min = INT_MAX;
		max = INT_MIN;
		while (lst != NULL)
		{
			if (lst->index == i && lst->nbr < min)
				min = lst->nbr;
			if (lst->index == i && lst->nbr > max)
				max = lst->nbr;
			lst = lst->next;
		}
		while (args->pila->nbr != min)
		{
			if (args->pila->index == i)
				rotate_a(args);
			else
				push_b(args);
		}
		push_b(args);
		while (args->pilb->nbr != max)
			rotate_b(args);
		push_a(args);
		i++;
	}
	sort_three(args);
	while (args->pilb != NULL)
		push_a(args);
}
void sort_big(t_args *args)
{
	int i;
	int size;
	int min;
	int max;
	t_stk *lst;
	
	size = ft_lst_size(args->pila);
	i = 0;
	while (i < size)
	{
		lst = args->pila;
		min = INT_MAX;
		max = INT_MIN;
		while (lst != NULL)
		{
			if (lst->index == i && lst->nbr < min)
				min = lst->nbr;
			if (lst->index == i && lst->nbr > max)
				max = lst->nbr;
			lst = lst->next;
		}
		while (args->pila->nbr != min)
		{
			if (args->pila->index == i)
				rotate_a(args);
			else
				push_b(args);
		}
		push_b(args);
		while (args->pilb->nbr != max)
			rotate_b(args);
		push_a(args);
		i++;
	}
}
