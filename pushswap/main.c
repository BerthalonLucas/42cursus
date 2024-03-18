/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:30:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/16 02:19:49 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_struct(t_args *args)
{
	if (args)
	{
		if (args->pila)
			ft_lstclear_pil(args->pila);
		if (args->pilb)
			ft_lstclear_pil(args->pilb);
	}
}

t_stk	*ft_lst_new(t_args *args, int nbr)
{
	t_stk	*new;

	new = malloc(sizeof(t_stk));
	if (!new)
	{
		free_struct(args);
		exit (1);
	}	
	new->next = NULL;
	new->prev = NULL;
	new->nbr = nbr;
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

void	init_args(t_args *args)
{
	args->pila = NULL;
	args->pilb = NULL;
}

int main(int ac, char **av)
{
	t_args	args;
	(void)av;
	(void)ac;
	init_args(&args);
	ft_list_add_back(&args, ft_lst_new(&args, 42), 'a');
	ft_list_add_back(&args, ft_lst_new(&args, 24), 'a');
	ft_list_add_back(&args, ft_lst_new(&args, 42), 'b');
	ft_list_add_back(&args, ft_lst_new(&args, 24), 'b');
	ft_printf("pilA nbr %d Index : %d\n", args.pila->nbr, args.pila->index);
	ft_printf("pilA nbr %d Index : %d\n", args.pila->next->nbr, args.pila->next->index);
	ft_printf("pilB nbr %d Index : %d\n", args.pilb->nbr, args.pilb->index);
	ft_printf("pilB nbr %d Index : %d\n", args.pilb->next->nbr, args.pilb->next->index);
	free_struct(&args);
	return (0);
}