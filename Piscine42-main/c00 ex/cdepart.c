/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdepart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:35:06 by lberthal          #+#    #+#             */
/*   Updated: 2023/08/23 23:27:56 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_mescouilles(char c);

int	main(void)
{
	ft_mescouilles('*');
}

void	ft_mescouilles(char c)
{
	write(1, &c, 1);
}
