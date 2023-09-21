/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:57:43 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/18 22:01:40 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void ft_putstr_rec(char *str)
{
	if (str[0] == '\0')
		write (1, "\n", 1);
	else
	{
		write (1, &str[0], 1);
		ft_putstr_rec(&str[1]);
	}
}

int main(void)
{
	char str[] = "c'est une dinguerie";

	ft_putstr_rec(str);
}