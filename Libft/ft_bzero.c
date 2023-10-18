/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:26:26 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/18 21:05:40 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

int main(void)
{
	unsigned char str[] = "coucou les petits loups";
	

	printf("%s\n", str);
	ft_bzero(str, 15);
	printf("%s\n", str);
}
