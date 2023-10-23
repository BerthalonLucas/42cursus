/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:24:24 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/22 19:07:44 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <bsd/string.h> 
//besoin de compiler avec le flag -lbsd ex : gcc file.c -lbsd <-- a droite

int	ft_isdigit(int c);
int	ft_isalpha(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_atoi(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
void *ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int	toupper(int c);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
void *calloc(size_t nmemb, size_t size);
char *strdup(const char *s);
char *ft_strnstr(const char *big, const char *little, size_t len);




#endif // LIBFT_H