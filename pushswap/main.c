/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:30:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/19 12:33:43 by lberthal         ###   ########.fr       */
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
long	ft_atol(char *str)
{
	int	i;
	long	sign;
	long	res;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	ft_isdigit(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	if (*s == '-')
		i++;
	while (i++, s[i] >= '0' && s[i] <= '9')
	if (ft_strlen(s) < i)
		return (0);
	return (1);
}
int	ft_parsing(t_args args, int ac, char **av)
{

	int i;

	i = 0;
	while (i < ac)
	{
		if (ft_isdigit(av[i]))
			
		if (ft_altol(av[i]) > INT_MAX)
			return (0);
	}
	
}

int main(int ac, char **av)
{
	t_args	args;
	int i;

	i = 0;
	init_args(&args);
	ft_parsing(&args, ac, av);
	return (free_struct(&args), 0);
}