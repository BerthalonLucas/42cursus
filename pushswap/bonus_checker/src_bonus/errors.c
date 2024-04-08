/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:13:04 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/08 23:37:07 by root             ###   ########.fr       */
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

void	ft_error(t_args *args)
{
	ft_putendl_fd("Error\n", 2);
	free_struct(args);
	exit(1);
}
