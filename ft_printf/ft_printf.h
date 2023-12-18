/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:24:24 by lberthal          #+#    #+#             */
/*   Updated: 2023/12/18 19:57:33 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	selection(char c, va_list args);
int	ft_printf(const char *s, ...);
int	string(va_list args);
int	decimale(va_list args);
int	integer(va_list args);
int	unsinged_decimale(va_list args);
int	putnbr(long int i);
int	character(va_list args);
int	hexa_lower(unsigned long long i, char *base);
int	hexa_upper(unsigned long long i, char *base);
int	pointer(unsigned long long i, char *base);
int	hexa_bases(va_list args, char c);
int	count(long int i);
int	count_hex(unsigned long long int i);

#endif // FT_PRINTF_H