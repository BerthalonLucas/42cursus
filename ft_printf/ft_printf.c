/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:29 by lucas             #+#    #+#             */
/*   Updated: 2023/12/02 00:00:15 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int select(const char *s, ...)
{
    if (s == 'c')
        P_char(va_arg);
        
}

int    ft_printf(const char *s, ...)
{
    va_list args;
    va_start (args, s);
    while (s)
    {
        if (s == '%')
        {
            s++;
            select(s, args);
        }
    }
}