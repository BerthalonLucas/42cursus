/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:13:04 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/05 00:14:35 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_struct(t_args *args)
{
	if (args)
	{
		if (args->pila)
		{
			// ft_printf("freeing pila [%p]\n", args->pila);
			ft_lstclear_pil(&(args->pila));
		}
		if (args->pilb)
		{
			// ft_printf("freeing pilb [%p]\n", args->pilb);
			ft_lstclear_pil(&(args->pilb));
		}
	}
}

void ft_error(t_args *args, char *error)
{
	ft_printf("Error : %s\n", error);
	// ft_printf("\nError\n");
	free_struct(args);
	exit(1);
}