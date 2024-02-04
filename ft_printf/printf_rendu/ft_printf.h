/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:24:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/02/04 21:50:52 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

typedef struct s_pf
{
	int		cp;
	int		neg;
	char	*s;

}	t_pf;

int	selection(char c, va_list args, t_pf *pf);
int	ft_printf(const char *s, ...);
int	string(va_list args, t_pf *pf);
int	decimale(va_list args, t_pf *pf);
int	integer(va_list args, t_pf *pf);
int	unsinged_decimale(va_list args, t_pf *pf);
int	putnbr(long int i, t_pf *pf);
int	character(va_list args, t_pf *pf);
int	hexa_lower(unsigned long long i, char *base, t_pf *pf);
int	hexa_upper(unsigned long long i, char *base, t_pf *pf);
int	pointer(unsigned long long i, char *base, t_pf *pf);
int	hexa_bases(va_list args, char c, t_pf *pf);
int	count(long int i);
int	count_hex(unsigned long long int i);

#endif // FT_PRINTF_H