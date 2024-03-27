/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:12:38 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/27 00:30:10 by lberthal         ###   ########.fr       */
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
		ft_printf("%p %p\n", temp, next);
		free(temp);
		temp = next;
	}
	*lst = NULL;
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