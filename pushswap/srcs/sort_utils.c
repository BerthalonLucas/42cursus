/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:11:17 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/05 07:23:47 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

t_stk	*find_smallest(t_args *args)
{
	t_stk *tmp;
	t_stk *ret;
	int smallest;

	tmp = args->pila;
	smallest = INT_MAX;
	ret = NULL;
	while (tmp)
	{
		if (tmp->nbr < smallest)
		{
			smallest = tmp->nbr;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}
t_stk	*find_biggest(t_args *args)
{
	t_stk *tmp;
	t_stk *ret;
	int biggest;

	tmp = args->pila;
	biggest = INT_MIN;
	ret = NULL;
	while (tmp)
	{
		if (tmp->nbr > biggest)
		{
			biggest = tmp->nbr;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}
void	pos(t_args *args)
{
	t_stk *tmp;
	int i;

	i = 0;
	if (args->pila)
	{
		tmp = args->pila;
		while (tmp)
		{
			tmp->pos = i;
			i++;
			tmp = tmp->next;
		}	
	}
	pos_b(args);
	ft_lst_size(args);
	above_mediane(args);
}
void pos_b(t_args *args)
{
	t_stk *tmp;
	int i;

	i = 0;
	if (args->pilb)
	{
		tmp = args->pilb;
		while (tmp)
		{
			tmp->pos = i;
			i++;
			tmp = tmp->next;
		}
	}
}
t_stk	*find_neerest_bigger(t_args *args, int number)
{
	t_stk	*tmpa;
	t_stk	*neerest_bigger;

	tmpa = args->pila;
	neerest_bigger = NULL;
	while (tmpa)
	{
		if (tmpa->nbr > number)
		{
			if (neerest_bigger && (tmpa->nbr < neerest_bigger->nbr))
			{
				neerest_bigger = tmpa;
			}
			else if (!neerest_bigger)
				neerest_bigger = tmpa;	
		}
		tmpa = tmpa->next;
	}
	return (neerest_bigger);
}
void	find_target(t_args *args)
{
	t_stk	*tmpb;
	
	if (args->pilb)
	{
		tmpb = args->pilb;
		while (tmpb)
		{
			tmpb->target = find_neerest_bigger(args, tmpb->nbr);
			if (!tmpb->target)
				tmpb->target = find_smallest(args);
			tmpb = tmpb->next;
		}
	}
}
void	above_mediane(t_args *args)
{
	t_stk	*tmp;
	
	if (args->pila)
	{
		tmp = args->pila;
		while (tmp)
		{
			if (tmp->pos <= (args->lst_size_a / 2))
				tmp->above_mediane = true;
			else
				tmp->above_mediane = false;
			tmp = tmp->next;
		}
	}
	above_mediane_b(args);
}
void	above_mediane_b(t_args *args)
{
	t_stk *tmp;
	
	if (args->pilb)
	{
		tmp = args->pilb;
		while (tmp)
		{
			if (tmp->pos <= (args->lst_size_b / 2))
				tmp->above_mediane = true;
			else
				tmp->above_mediane = false;
			tmp = tmp->next;
		}
	}
}

void	push_cost(t_args *args)
{
	t_stk	*tmpb;

	tmpb = args->pilb;
	if (args->pilb)
	{
		while (tmpb)
		{
			if (tmpb->target->above_mediane && tmpb->above_mediane)
				push_cost_above(tmpb);
			else if (!(tmpb->target->above_mediane) && !(tmpb->above_mediane))
				push_cost_bellow(args, tmpb);
			else
				push_cost_else(args, tmpb);
			tmpb = tmpb->next;
		}
	}
}
void	push_cost_above(t_stk *tmpb)
{
	int size_diff_a;
	int size_diff_b;

	size_diff_b = tmpb->pos;
	size_diff_a = tmpb->target->pos;
	if (size_diff_b == size_diff_a) 
	{
		tmpb->push_cost = size_diff_a;
		tmpb->rr = size_diff_a; 
	}
	else if (size_diff_b < size_diff_a)
	{
		tmpb->push_cost = size_diff_b + (size_diff_a - size_diff_b);
		tmpb->rr = size_diff_b;
		tmpb->ra = size_diff_a - size_diff_b;
	}
	else if (size_diff_b > size_diff_a)
	{
		tmpb->push_cost = size_diff_a + (size_diff_b - size_diff_a);
		tmpb->rr = size_diff_a;
		tmpb->ra = size_diff_b - size_diff_a;
	}

}

t_stk	*find_cheapest(t_stk *pilb)
{
	t_stk	*tmpb;
	t_stk	*cheapest_s;

	tmpb = pilb;
	cheapest_s = tmpb;
	while (tmpb)
	{
		if (tmpb->push_cost < cheapest_s->push_cost)
			cheapest_s = tmpb;
		tmpb = tmpb->next;
	}
	return (cheapest_s);
}

void	push_cost_bellow(t_args *args, t_stk *tmpb)
{
	int size_diff_a;
	int size_diff_b;
	
	size_diff_b = args->lst_size_b - tmpb->pos;
	size_diff_a = args->lst_size_a - tmpb->target->pos;
	if (size_diff_b == size_diff_a)
	{
		tmpb->push_cost = size_diff_b;
		tmpb->rrr = size_diff_b;
	}
	else if (size_diff_b < size_diff_a)
	{
		tmpb->push_cost = size_diff_b + (size_diff_a - size_diff_b);
		tmpb->rrr = size_diff_b;
		tmpb->rra = size_diff_a - size_diff_b;
	}
	else
	{
		// Dans ce cas, size_diff_b > size_diff_a
		tmpb->push_cost = size_diff_a + (size_diff_b - size_diff_a);
		tmpb->rrr = size_diff_a;
		tmpb->rrb = size_diff_b - size_diff_a;
	}
}
void	push_cost_else(t_args *args, t_stk *tmpb)
{
	int	size_diff_a;
	int	size_diff_b;

	size_diff_a = args->lst_size_a - tmpb->target->pos;
	size_diff_b = args->lst_size_b - tmpb->pos;
	if (tmpb->above_mediane)
	{
		tmpb->push_cost = tmpb->pos + size_diff_a;
		tmpb->rb = tmpb->pos;
		tmpb->rra = args->lst_size_a - tmpb->target->pos;
	}
	else
	{
		tmpb->push_cost = tmpb->target->pos + size_diff_b;
		tmpb->ra = tmpb->target->pos;
		tmpb->rrb = args->lst_size_b - tmpb->pos;
	}
}


// void	push_cost_bellow(t_args *args, t_stk *tmpb)
// {
// 	if ((args->lst_size_b - tmpb->pos) == (args->lst_size_a - tmpb->target->pos))
// 		tmpb->push_cost = (args->lst_size_b - tmpb->pos);
// 	else if ((args->lst_size_b - tmpb->pos) < (args->lst_size_a - tmpb->target->pos))
// 		tmpb->push_cost = (args->lst_size_b - tmpb->pos) + (args->lst_size_a - tmpb->target->pos);
// 	else if ((args->lst_size_b - tmpb->pos) > (args->lst_size_a - tmpb->target->pos))
// 	{
// 		if (args->lst_size_a < args->lst_size_b)
// 			tmpb->push_cost = (args->lst_size_b - tmpb->pos);
// 		else if (args->lst_size_a > args->lst_size_b)
// 			tmpb->push_cost = (args->lst_size_a - tmpb->target->pos);
// 		else
// 			tmpb->push_cost = (args->lst_size_a - tmpb->target->pos) + (args->lst_size_b - tmpb->pos); // double rotate + rotate du reste de l'autre pile
// 	}
// }

// void push_cost_above(t_args *args, t_stk *tmpb)
// {
// 	if ((args->lst_size_b - tmpb->pos) < (args->lst_size_a - tmpb->target->pos))
// 		tmpb->push_cost = (tmpb->pos + (tmpb->target->pos - tmpb->pos));
// 	else if ((args->lst_size_b - tmpb->pos) > (args->lst_size_a - tmpb->target->pos))
// 		tmpb->push_cost = (tmpb->target->pos + (tmpb->pos - tmpb->target->pos));
// 	else if ((args->lst_size_b - tmpb->pos) == (args->lst_size_a - tmpb->target->pos))
// 	{
// 		if (args->lst_size_a < args->lst_size_b)
// 			tmpb->push_cost = (tmpb->target->pos + (tmpb->pos - tmpb->target->pos));
// 		else
// 			tmpb->push_cost = (args->lst_size_b - tmpb->pos);
// 	}
// }