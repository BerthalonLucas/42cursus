/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:12:39 by anonymous         #+#    #+#             */
/*   Updated: 2023/09/19 01:41:06 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

int main(int ac, char **av)
{
	int count;
	int j;
	char *temp;
	

	count = 2;
	while (count >= 1)
	{
		count = 0;
		j = 1;
		while ((ft_strcmp(av[j], av[j + 1]) < 0) && (av[j + 1]))
		{
			temp = av[j];
			av[j] = av[j + 1];
			av[j + 1] = temp;
			j++;
			count++;
		}
	}
	j = 1;
	while (av[j])
	{
		ft_putstr(av[j]);
		write (1, "\n", 1);
		j++;
	}
	(void)ac;
}