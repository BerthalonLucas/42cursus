/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:07:19 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/09 20:08:15 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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
	ft_putendl_fd("Error", 2);
	free_struct(args);
	exit(1);
}
