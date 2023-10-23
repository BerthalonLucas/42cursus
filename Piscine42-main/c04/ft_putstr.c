/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:00:04 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/08 13:23:03 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char	*str)
{
	int i;

	i = 0;
	while (str[i] && str[i] <= ft_strlen(str))
	{
	write (1, &str[i], 1);
	i++;
	}
}

int main(void)
{
	char	str[] = "je m'en fou";
	ft_putstr(str);
	printf("%d\n", puts(str));
}