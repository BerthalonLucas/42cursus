/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:03:10 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/14 16:49:11 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	else if (*str == '\0')
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
