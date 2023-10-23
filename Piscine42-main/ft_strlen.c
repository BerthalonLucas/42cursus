/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:25:50 by lberthal          #+#    #+#             */
/*   Updated: 2023/08/28 17:45:57 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)
{
	unsigned int i;
	
	i = 0;
	while (str[i])
	{
		i++;
	}
	return(0);
}

int main(void)
{
	char	strg[] = "Hey mates";
	ft_strlen(strg);
}
