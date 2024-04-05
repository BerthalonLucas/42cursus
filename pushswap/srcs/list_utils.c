/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:12:38 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/05 00:14:04 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_lstclear_pil(t_stk **lst)
{
	t_stk	*temp;
	t_stk	*next;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		// ft_printf("%p %p\n", temp, next);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
void	ft_lst_size(t_args *args)
{
	t_stk	*tmpa;
	int	i;

	i = 0;
	tmpa = args->pila;
	if(tmpa)
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
	int	i;

	i = 0;
	tmpb = args->pilb;
	if(tmpb)
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
