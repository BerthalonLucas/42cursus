/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:13:04 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/07 09:04:48 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_struct(t_args *args)
{
	if (args)
	{
		if (args->pila)
			ft_lstclear_pil(&(args->pila));
		if (args->pilb)
			ft_lstclear_pil(&(args->pilb));
	}
}

void	ft_error(t_args *args, char *error)
{
	ft_printf("Error : %s\n", error);
	free_struct(args);
	exit(1);
}
