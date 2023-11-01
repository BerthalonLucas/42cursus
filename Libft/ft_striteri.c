/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:02:49 by lberthal          #+#    #+#             */
/*   Updated: 2023/11/01 15:49:07 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void iter(unsigned int	i, char *s)
// {
// 		*s = (char)(i + *s);
// }

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned	int	index;
		
	if (!s || !f)
		return;
	if (s[0] == '\0')
		return;
	index = 0;
	while (s[index])
	{
		(*f)(index, &s[index]);
		index++;
	}
}

// int main(void)
// {
// 	char str[] = "abcd0 ";
// 	ft_striteri(str, &iter);
// 	printf("%s\n", str);
// }