/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:26:55 by lberthal          #+#    #+#             */
/*   Updated: 2023/10/19 20:26:56 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <bsd/string.h>
#include <stddef.h>

//besoin de compiler avec le flag -lbsd ex : gcc file.c -lbsd <-- a droite


int main(void)
{
	// ----------------------------------------------
    // testes for ft_atoi
    //----------------------------------------------
// 	char *str = "   -2147483648";
// 	char *str1 = "   -2147483648";
//  char str2 = "   \t\n\v\r\f-1234567890";

// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str1));
//  printf("%d\n", ft_atoi(str2));
//  printf("%d\n", atoi(str2));
    // ----------------------------------------------
    // testes for ft_bzero
    //----------------------------------------------
// 	char str[] = "petit test pour voir";
// 	char str1[] = "petit test pour voir";
// 	ft_bzero(str, 4);
// 	bzero(str1, 4);
// 	printf("%s\n", str);
// 	printf("%s\n", str1);
    // ----------------------------------------------
    // testes for ft_calloc
    //----------------------------------------------
// 	char *str = ft_calloc(4, sizeof(char));
// 	char *str1 = calloc(4, sizeof(char));
// 	printf("%s\n", str);
// 	printf("%s\n", str1);
// 	free(str);
// 	free(str1);
    // ----------------------------------------------
    // testes for ft_isalnum
    //----------------------------------------------
// 	int i = 0;
// 	while (i < 128)
// 	{
// 		if (ft_isalnum(i) != isalnum(i))
// 			printf("%d\n", i);
// 		i++;
// 	}
    // ----------------------------------------------
    // testes for ft_isalpha
    //----------------------------------------------
// 	int i = 0;
// 	while (i < 128)
// 	{
// 		if (ft_isalpha(i) != isalpha(i))
// 			printf("%d\n", i);
// 		i++;
// 	}
    // ----------------------------------------------
    // testes for ft_isascii
    //----------------------------------------------
// 	int i = 0;
// 	while (i < 128)
// 	{
// 		if (ft_isascii(i) != isascii(i))
// 			printf("%d\n", i);
// 		i++;
// 	}
    // ----------------------------------------------
    // testes for ft_isdigit
    //----------------------------------------------
// 	int i = 0;
// 	while (i < 128)
// 	{
// 		if (ft_isdigit(i) != isdigit(i))
// 			printf("%d\n", i);
// 		i++;
// 	}
    // ----------------------------------------------
    // testes for ft_isprint
    //----------------------------------------------
// 	int i = 0;
// 	while (i < 128)
// 	{
// 		if (ft_isprint(i) != isprint(i))
// 			printf("%d\n", i);
// 		i++;
// 	}
    // ----------------------------------------------
    // testes for ft_memchr
    //----------------------------------------------
// 	char str[] = "petit test pour voir";
// 	char str1[] = "petit test pour voir";
// 	printf("%s\n", ft_memchr(str, 't', 4));
// 	printf("%s\n", memchr(str1, 't', 4));
    // ----------------------------------------------
    // testes for ft_memcmp
    //----------------------------------------------
// 	printf("%d\n", ft_memcmp("test", "test", 111));
// 	printf("%d\n", memcmp("test", "test", 111));
    // ----------------------------------------------
    // testes for ft_memcpy
    //----------------------------------------------
// 	unsigned char dest[] = "hello world";
// 	unsigned char dest1[] = "hello world";
// 	const unsigned char src[] = "tests";
// 	const unsigned char src1[] = "tests";

// 	printf("%s\n", (unsigned char*)ft_memcpy(dest, src, 5));
// 	printf("%s\n", (unsigned char*)memcpy(dest1, src1, 5));
    // ----------------------------------------------
    // testes for ft_memmove
    //----------------------------------------------
// 	unsigned char dest[] = "hello world";
// 	unsigned char dest1[] = "hello world";

// 	printf("%s\n", (unsigned char*)ft_memmove(dest + 6, dest, 5));
// 	printf("%s\n", (unsigned char*)memmove(dest1 + 6, dest1, 5));
    // ----------------------------------------------
    // testes for ft_memset
    //----------------------------------------------
// 	unsigned char str[] = "je m'en fou de ta life";
// 	unsigned char str2[] = "je m'en fou de ta life";
// 	printf("%s\n", str);
// 	printf("after ft_memeset : %s\n", (char*)ft_memset(str, 120, 9));
// 	printf("after memset : %s\n", (char*)memset(str2, 120, 5));
    // ----------------------------------------------
    // testes for ft_strchr
    //----------------------------------------------
// 	printf("%s\n", ft_strchr((const char*)"testducona", 0));
//  printf("%s\n", strchr((const char*)"testducona", 0));
    // ----------------------------------------------
    // testes for ft_strdup 
    //----------------------------------------------
// 	char *str = "";
// 	char *str1 = "";
// 	char *rep = ft_strdup(str);
// 	char *rep1 = strdup(str1);
	
// 	printf("%s\n", ft_strdup(rep));
// 	printf("%s\n", strdup(rep1));
// 	free(rep);
// 	free(rep1);
    // ----------------------------------------------
    // testes for ft_strlcat
    //----------------------------------------------
// 	char dest[] = "1234";
// 	const char *src = "123456789";
// 	char dest1[] = "1234";
// 	const char *src1 = "123456789";
	
// 	printf("%ld\n", strlcat(dest1, src1, 12));
// 	printf("%s\n", dest1);
// 	printf("%s\n", src1);
// 	printf("%ld\n", ft_strlcat(dest, src, 12));
// 	printf("%s\n", dest);
// 	printf("%s\n", src);
    // ----------------------------------------------
    // testes for ft_strlcpy
    //----------------------------------------------
// 	char str[] = "petit test pour voir";
// 	const char str1[] = "autre se";

// 	printf("%lu\n", ft_strlcpy(str, str1, 4));
// 	printf("%lu\n", strlcpy(str, str1, 4));
    // ----------------------------------------------
    // testes for ft_strlen
    //----------------------------------------------
// 	printf("%lu\n", ft_strlen("test"));
// 	printf("%lu\n", strlen("test"));
// ----------------------------------------------
    // testes for ft_strncmp
    //----------------------------------------------
// 	const char s1[] = "test";
// 	const char s2[] = "";
// 	const char s3[] = "test";
// 	const char s4[] = "";
	
// 	printf("%d\n", ft_strncmp(s1, s2, 0));
// 	printf("%d\n", strncmp(s3, s4, 0));
    // ----------------------------------------------
    // testes for ft_strnstr
    //----------------------------------------------
// // printf("%s\n", strnstr("test dans le tester", "", 6));
// 	char *result = strnstr("aaabcabcd", "abcd", 9);
// 	if (result == NULL)
// 		printf("c'est bien NULL\n");
// 	else
// 		printf("%s\n", result);

// 	// test of my function
// 	// printf("%s\n", ft_strnstr("test dans le tester", "", 6));
// 	char *result1 = ft_strnstr("aaabcabcd", "abcd", 9);
// 	if (result1 == NULL)
// 		printf("c'est bien NULL\n");
// 	else
// 		printf("%s\n", result1);
    // ----------------------------------------------
    // testes for ft_strrchr
    //----------------------------------------------
// 	printf("%s\n", ft_strrchr("teste", 'e'));
// 	printf("%s\n", strrchr("teste", 'e'));
    // ----------------------------------------------
    // testes for ft_tolower
    //----------------------------------------------
// 	int i = 0;
// 	while (i < 128)
// 	{
// 		if (ft_tolower(i) != tolower(i))
// 			printf("%d\n", i);
// 		i++;
// 	}
    // ----------------------------------------------
    // testes for ft_toupper
    //----------------------------------------------
	// int i = 0;
	// while (i < 128)
	// {
	// 	if (ft_toupper(i) != toupper(i))
	// 		printf("%d\n", i);
	// 	i++;
	// }
    // ----------------------------------------------
    // testes for ft_substr
    //----------------------------------------------
}