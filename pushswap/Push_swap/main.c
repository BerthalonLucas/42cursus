/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:30:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/16 02:19:49 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int argc, char **argv)
{
    t_args args;

    if (argc > 1)
    {
        if (!parse_args(argc, argv, &args))
        {
            ft_putstr_fd("Error\n", STDERR_FILENO);
            return (1);
        }
        push_swap(&args);
        free_stacks(&args);
    }
    return (0);
}
