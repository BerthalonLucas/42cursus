/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:24:24 by lberthal          #+#    #+#             */
/*   Updated: 2023/12/16 21:03:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int selection(const char *s,char c, va_list args);
int    ft_printf(const char *s, ...);
int P_string(va_list args);
int P_decimale(va_list args);
int P_interger(va_list args);
int P_unsinged_decimale(va_list args);
int putnbr(long int i);
int P_char(va_list args);
int P_hexa_lower(unsigned long long i, char *base);
int P_hexa_upper(unsigned long long i, char *base);
int P_pointer(unsigned long long i, char *base);
int hexa_bases(va_list args, const char *s);
int count(long int i);
int count_hex(long int i);



#endif // FT_PRINTF_H