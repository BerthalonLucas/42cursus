/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:11:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/09 00:01:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_args *args)
{
	int		size;
	t_stk	*lst;
	t_stk	*pmax;
	int		max;

	size = args->lst_size_a;
	while (size--, size > 0)
	{
		lst = args->pila;
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

bool	ft_check_double(t_stk *pila)
{
	t_stk	*actuel;
	t_stk	*comp;

	actuel = pila;
	while (actuel != NULL)
	{
		comp = actuel->next;
		while (comp != NULL)
		{
			if (actuel->nbr == comp->nbr)
				return (true);
			comp = comp->next;
		}
		actuel = actuel->next;
	}
	return (false);
}

void	ft_insert(t_args *args, char **av, int ac)
{
	int		i;
	long	value;

	i = 1;
	while (i < ac)
	{
		value = atol(av[i]);
		ft_list_add_back(args, ft_lst_new(args, value), 'a');
		i++;
	}
	if (ft_check_double(args->pila))
		ft_error(args);
	ft_lst_size(args);
	set_index(args);
}

bool	ft_is_digit(const char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (false);
	if (*s == '-')
		i++;
	while (i++, s[i] >= '0' && s[i] <= '9')
		;
	if ((int)ft_strlen(s) != i)
		return (false);
	return (true);
}

void	ft_parsing(int ac, char **av)
{
	int		i;
	long	y;

	i = 1;
	while (i < ac)
	{
		y = ft_atol(av[i]);
		if (!ft_is_digit(av[i]))
			ft_error(NULL);
		if (y > INT_MAX || y < INT_MIN)
			ft_error(NULL);
		i++;
	}
}
