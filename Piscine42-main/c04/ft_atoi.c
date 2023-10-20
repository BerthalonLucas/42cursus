/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:55:11 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/15 18:19:28 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_atoi(const char *str)
{
	int i;
	int a;
	int entier;

	i = 0;
	a = 1;
	entier = 0;
	if (!(str[i]))
		return (0);
	while (( str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			a = a * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		entier = entier * 10 + str[i] - '0';
		i++;
	}
	entier = entier * a;
	return (entier);
}
/*
int main(void)
{
	const char str[] = "  		 +-+-++-47859zx47   ";

	printf("%d\n", ft_atoi(str));
}*/