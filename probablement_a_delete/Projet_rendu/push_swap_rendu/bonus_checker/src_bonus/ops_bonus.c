/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:08:54 by lberthal          #+#    #+#             */
/*   Updated: 2024/04/09 20:09:05 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	ops(t_args *args, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		swap_a(args);
	else if (!ft_strncmp(op, "sb\n", 3))
		swap_b(args);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(args);
	else if (!ft_strncmp(op, "pa\n", 3))
		push_a(args);
	else if (!ft_strncmp(op, "pb\n", 3))
		push_b(args);
	else if (!ft_strncmp(op, "ra\n", 3))
		rotate_a(args);
	else if (!ft_strncmp(op, "rb\n", 3))
		rotate_b(args);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(args);
	else if (!ft_strncmp(op, "rra\n", 4))
		reverse_rotate_a(args);
	else if (!ft_strncmp(op, "rrb\n", 4))
		reverse_rotate_b(args);
	else if (!ft_strncmp(op, "rrr\n", 4))
		rrr(args);
	else
		ft_error(args);
}
