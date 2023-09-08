/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:55:11 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/08 14:30:52 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_posneg(*str)
{
	int mnbr;
	int i;

	i = 0;
	mnbr = 0;
	while (str[i])
	{
		if (str[i] == '-')
			mnbr++;
		else
			i++;
	}
	mnbr = mnbr % 2;
	if (mbr >= 1)
		return (0);
	else
		return (1);
}

int ft_atoi(char *str)
{
	int i;
	int signe;
	int entier;


	i = 0;
	signe = 1;

	while (str[i] == ' ' || (str][i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && <= '9')
	{
		entier = entier * 10 + src[i] - '0';
		i++;
	}
	if (ft_posneg(str) == 0)
		

}
