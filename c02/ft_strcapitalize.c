/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:58:59 by lberthal          #+#    #+#             */
/*   Updated: 2023/08/31 19:00:10 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	alphanum_o(char	*str, int i);

int	alphanum(char	*str, int i)
{
	if (alphanum_o(str, i) < 3)
		return (1);
	else
		return (0);
}

int	alphanum_o(char	*str, int i)
{
	if (str[i] >= 65 && str[i] <= 90)
		return (0);
	else if (str[i] >= 97 && str[i] <= 122)
		return (1);
	else if (str[i] >= 48 && str[i] <= 57)
		return (2);
	else
		return (3);
}

char	*ft_strcapitalize(char	*str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		while (alphanum(str, j) == 1)
		{
			if (alphanum_o(str, j) == 1 && i == j)
				str[j] = str[j] - 32;
			else if (alphanum_o(str, j) == 0 && i != j)
				str[j] = str[j] + 32;
			j++;
		}
		i = j;
	i++;
	j++;
	}
	return (str);
}
/*
int main(void)
{
    char    str[] = "bonj42our MonN aMIIIis c'est 42muLHouse";
    ft_strcapitalize(str);
    printf("and now, with the uppercases --> %s\n", str);
}
*/
