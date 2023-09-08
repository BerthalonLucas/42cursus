/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:15:34 by lberthal          #+#    #+#             */
/*   Updated: 2023/08/29 17:46:43 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <unistd.h>
*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int a;
	int	b;
	int divi;
	int modu;
	int *div;
	int	*mod;

	a = 42;
	b = 10;
	div = &divi;
	mod = &modu;
	ft_div_mod(a, b, div, mod);
	printf("divise : %d modulo : %d\n", *div, *mod);
   return(0);	
}
*/
