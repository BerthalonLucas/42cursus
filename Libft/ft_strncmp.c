/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:28:02 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/20 16:58:30 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i <= n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((int)s1[i] - (int)s2[i]);
	}
	return (0);
}

// int main(void)
// {
// 	const char s1[] = "je ne sais pas quoi ecrire";
// 	const char s2[] = "je ne sais pas quoi 1crire";
// 	const char s3[] = "je ne sais pas quoi ecrire";
// 	const char s4[] = "je ne sais pas quoi 1crire";
	
// 	printf("%d\n", ft_strncmp(s1, s2, 12));
// 	printf("%d\n", strncmp(s3, s4, 12));
// }