/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:12:38 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/08 23:37:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stk	*ft_lst_new(t_args *args, int nbr)
{
	t_stk	*new;

	new = malloc(sizeof(t_stk));
	if (!new)
		ft_error(args);
	init_chain(new, nbr);
	return (new);
}

t_stk	*find_last(t_stk *lst)
{
	t_stk	*temp;

	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_list_add_back(t_args *args, t_stk *new_lst, char pile)
{
	t_stk	*last;

	if (pile == 'a')
	{
		if (!args->pila)
			args->pila = new_lst;
		else
		{
			last = find_last(args->pila);
			last->next = new_lst;
			new_lst->prev = last;
		}
	}
	else
	{
		if (!args->pilb)
			args->pilb = new_lst;
		else
		{
			last = find_last(args->pilb);
			last->next = new_lst;
			new_lst->prev = last;
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
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
