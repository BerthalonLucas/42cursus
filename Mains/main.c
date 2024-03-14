/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:26:55 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/14 00:45:52 by lberthal         ###   ########.fr       */
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
	char *str = "   -2147483648";
	char *str1 = "   -2147483648";
	char *str2 = "   \t\n\v\r\f-1234567890";

	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str1));
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", atoi(str2));
	// ----------------------------------------------
	// testes for ft_bzero
	//----------------------------------------------
	// char str[] = "petit test pour voir";
	// char str1[] = "petit test pour voir";
	
	// ft_bzero(str, 4);
	// bzero(str1, 4);
	// ft_printf("%s\n", str);
	// ft_printf("%s\n", str1);
	// return (0);
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
	// char *str = "Hello World";
	
	// printf("%s\n", ft_substr(str, 0, 0));
	// return (0);
	// ----------------------------------------------
	// testes for ft_strjoin
	//----------------------------------------------
	// char *strt1;
	// char *strt1b;
	// char *strt2;
	// char *strt2b;
	// char *strt3;
	// char *strt3b;
	
	// strt1 = "concate";
	// strt1b = "nation";
	// strt2 = "";
	// strt2b = "";
	// strt3 = "";
	// strt3b = "devrait return null";
	
	// printf("%s\n", ft_strjoin(strt1, strt1b));
	// if (ft_strjoin(strt2, strt2b) == NULL)
	// 	return (printf("result NULL"));
	// if (ft_strjoin(strt3, strt3b) == NULL)
	// 	return (printf("result NULL"));
	// return (0);
	// ----------------------------------------------
	// testes for ft_strtrim
	//----------------------------------------------
	// 	char *str = "   xxx   xxx";
	// 	char *strt = " x";

	// 	printf("%s\n", ft_strtrim(str, strt));
	// ----------------------------------------------
	// testes for ft_itoa
	//----------------------------------------------
	// 	printf("%s\n", ft_itoa(-1));
	// 	printf("%s\n", ft_itoa(123456789));
	// 	printf("%s\n", ft_itoa(-123456789));
	// 	printf("%s\n", ft_itoa(0));
	// 	printf("%s\n", ft_itoa(1));
	// 	printf("%s\n", ft_itoa(2147483647));
	// 	printf("%s\n", ft_itoa(-2147483648));
	// ----------------------------------------------
	// testes for ft_split
	//----------------------------------------------
	// 	// int i = 0;
	// 	// char *str = "    lyigk iugvuvhj";
	// 	// char *str = "123456789";
	// 	// char *str = "545  516     651   ";
	// 	// char *str = "123  1234   12345  123456";
	// 	char c = ' ';
	
	// 	while (i < 10)
	// 	{
	// 		if (ft_split(str, c) == NULL)
	// 			return (printf("fonction NULL for STR"));
	// 		if (ft_split(str, c)[i] == NULL)
	// 		{
	// 			printf("String, NULL for STR\n");
	// 			return (0);
	// 		}
	// 		else
	// 			printf("%s\n", ft_split(str, c)[i]);
	// 		i++;
	// 	}
	// 	return (0);
	// ----------------------------------------------
	// testes for ft_strmapi
	//----------------------------------------------
	// 	char *result;

	// 	result = ft_strmapi("M'APPELLE MICHELLE", &lower);
	// 	printf("%s\n", result);
	// ----------------------------------------------
	// testes for ft_striteri
	//----------------------------------------------
	// 	char str[] = "abcd0 ";
	// 	ft_striteri(str, &iter);
	// 	printf("%s\n", str);
	// ----------------------------------------------
	// testes for ft_putchar_fd
	//----------------------------------------------
	// 	ft_putchar_fd('a', 1);
	// ----------------------------------------------
	// testes for ft_putendl_fd
	//----------------------------------------------
	// 	ft_putendl_fd("test", 1);
	// ----------------------------------------------
	// testes for ft_putnbr_fd
	//----------------------------------------------
	// 	ft_putnbr_fd(2147483647, 1);
	// ----------------------------------------------
	// testes for ft_putstr_fd
	//----------------------------------------------
	// 	ft_putstr_fd("test", 1);
	// ----------------------------------------------
	// testes for ft_lstnew
	//----------------------------------------------
	// 	int i;
	// 	t_list *test;
	
	// 	i = 14;
	// 	test = ft_lstnew(&i);
	// 	printf("%d\n", *((int *)(test->content)));
	// ----------------------------------------------
	// testes for ft_lstadd_front
	//----------------------------------------------
	// 	t_list **lst;
	// 	t_list *new;

	// 	lst = malloc(sizeof(t_list));
	// 	if (!lst)
	// 		return (0);	
	// 	new = malloc(sizeof(t_list));
	// 	if (!new)
	// 		return (0);
	
	// 	printf("%p\n", lst);
	// 	ft_lstadd_front(lst, new);
	// 	printf("%p\n", new);
	// 	free(lst);
	// 	free(new);
	// ----------------------------------------------
	// testes for ft_lstsize
	//----------------------------------------------
	// 	t_list *list;
	// 	t_list	*str1;
	// 	t_list	*str2;
	// 	t_list	*str3;
	
	// 	list = malloc(sizeof(t_list));
	// 	if (!list)
	// 		return (0);
	// 	str1 = malloc(sizeof(t_list));
	// 	if (!str1)
	// 		return (0);
	// 	str2 = malloc(sizeof(t_list));
	// 	if (!str2)
	// 		return (0);
	// 	str3 = malloc(sizeof(t_list));
	// 	if (!str3)
	// 		return (0);
	// 	list->next = str1;
	// 	str1->next = str2;
	// 	str2->next = str3;
	// 	str3->next = NULL;
	// 	printf("%d\n", ft_lstsize(list));
	// 	free(list);
	// 	free(str1);
	// 	free(str2);
	// 	free(str3);
	// ----------------------------------------------
	// testes for ft_lstlast
	//----------------------------------------------
	// 	t_list *list;
	// 	t_list	*str1;
	// 	t_list	*str2;
	// 	t_list	*str3;
	// 	t_list *list;
	// 	t_list	*str1;
	// 	t_list	*str2;
	// 	t_list	*str3;
	
	// 	list = malloc(sizeof(t_list));
	// 	if (!list)
	// 		return (0);
	// 	str1 = malloc(sizeof(t_list));
	// 	if (!str1)
	// 		return (0);
	// 	str2 = malloc(sizeof(t_list));
	// 	if (!str2)
	// 		return (0);
	// 	str3 = malloc(sizeof(t_list));
	// 	if (!str3)
	// 		return (0);
	// 	list->next = str1;
	// 	str1->next = str2;
	// 	str2->next = str3;
	// 	str3->next = NULL;
	// 	printf("%p\n", str3);
	// 	printf("%p\n", ft_lstlast(list));
	// 	free(list);
	// 	free(str1);
	// 	free(str2);
	// 	free(str3);
	// ----------------------------------------------
	// testes for ft_lstadd_back
	//----------------------------------------------
	// 	t_list *list;
	// 	t_list	*str1;
	// 	t_list	*str2;
	// 	t_list	*str3;
	// 	t_list	*new;

	// 	new = malloc(sizeof(t_list));
	// 	if (!new)
	// 		return (0);
	// 	list = malloc(sizeof(t_list));
	// 	if (!list)
	// 		return (0);
	// 	str1 = malloc(sizeof(t_list));
	// 	if (!str1)
	// 		return (0);
	// 	str2 = malloc(sizeof(t_list));
	// 	if (!str2)
	// 		return (0);
	// 	str3 = malloc(sizeof(t_list));
	// 	if (!str3)
	// 		return (0);
	// 	list->next = str1;
	// 	str1->next = str2;
	// 	str2->next = str3;
	// 	str3->next = NULL;
	// 	printf("%d\n", ft_lstsize(list));
	// 	ft_lstadd_back(&list, new);
	// 	printf("%d\n", ft_lstsize(list));
	// 	free(list);
	// 	free(str1);
	// 	free(str2);
	// 	free(str3);
	// 	free(new);
	// ----------------------------------------------
	// testes for ft_lstdelone
	//----------------------------------------------
	// 	t_list *list;
	// 	t_list	*str1;
	// 	t_list	*str2;
	// 	t_list	*str3;
	
	// 	list = malloc(sizeof(t_list));
	// 	if (!list)
	// 		return (0);
	// 	str1 = malloc(sizeof(t_list));
	// 	if (!str1)
	// 		return (0);
	// 	str2 = malloc(sizeof(t_list));
	// 	if (!str2)
	// 		return (0);
	// 	str3 = malloc(sizeof(t_list));
	// 	if (!str3)
	// 		return (0);
	// 	list->next = str1;
	// 	str1->next = str2;
	// 	str2->next = str3;
	// 	str3->next = NULL;
	// 	ft_lstdelone(list, &del);
	// 	// printf("%d\n", ft_lstsize(list));
	// 	ft_lstdelone(&list, &ft_del);
	// 	if (!list)
	// 		printf("Maillon bien supprimé");
	// 	else
	// 		printf("list toujours la bordel !");
	// 	// printf("%d\n", ft_lstsize(list));
	// 	free(list);
	// 	free(str1);
	// 	free(str2);
	// 	free(str3);
	// ----------------------------------------------
	// testes for ft_lstclear
	//----------------------------------------------
	// 	t_list *list;
	// 	t_list	*str1;
	// 	t_list	*str2;
	// 	t_list	*str3;

	// 	list = malloc(sizeof(t_list));
	// 	if (!list)
	// 		return (0);
	// 	str1 = malloc(sizeof(t_list));
	// 	if (!str1)
	// 		return (0);
	// 	str2 = malloc(sizeof(t_list));
	//  if (!str2)
	// 		return (0);
	// 	str3 = malloc(sizeof(t_list));
	// 	if (!str3)
	// 		return (0);
	// 	list->next = str1;
	// 	str1->next = str2;
	// 	str2->next = str3;
	// 	str3->next = NULL;
	// 	ft_lstclear(&list, &ft_del);
	// 	if (!list)
	// 		printf("Maillon bien supprimé");
	// 	else if (list == NULL)
	// 		printf("list bien mise a NULL");
	// 	// free(list);
	// 	// free(str1);
	// 	// free(str2);
	// 	// free(str3);
	// 	return (0);
	// ----------------------------------------------
	// testes for ft_lstiter
	//----------------------------------------------
	// 	t_list *list;
	// 	t_list	*str1;
	// 	t_list	*str2;
	// 	t_list	*str3;
	
	// 	list = malloc(sizeof(t_list));
	// 	if (!list)
	// 		return (0);
	// 	str1 = malloc(sizeof(t_list));
	// 	if (!str1)
	// 		return (0);
	// 	str2 = malloc(sizeof(t_list));
	// 	if (!str2)
	// 		return (0);
	//  str3 = malloc(sizeof(t_list));
	// 	if (!str3)
	// 		return (0);
	// 	list->content = strdup("a");
	// 	str1->content = strdup("b");
	// 	str2->content = strdup("c");
	// 	str3->content = strdup("d");
	// 	list->next = str1;
	// 	str1->next = str2;
	// 	str2->next = str3;
	// 	str3->next = NULL;
	// 	printf("%s\n", (char *)list->content);
	// 	printf("%s\n", (char *)str1->content);
	// 	printf("%s\n", (char *)str2->content);
	// 	printf("%s\n", (char *)str3->content);
	// 	ft_lstiter(list, &ft_plus);
	// 	printf("%s\n", (char *)list->content);
	// 	printf("%s\n", (char *)str1->content);
	// 	printf("%s\n", (char *)str2->content);
	// 	printf("%s\n", (char *)str3->content);
	// 	ft_lstclear(&list, &delete);
	// ----------------------------------------------
	// testes for ft_lstmap
	//----------------------------------------------
	// 	t_list *list;
	// 	t_list	*str1;
	// 	t_list	*str2;
	// 	t_list	*str3;
	
	// 	list = malloc(sizeof(t_list));
	// 	if (!list)
	// 		return (0);
	// 	str1 = malloc(sizeof(t_list));
	// 	if (!str1)
	// 		return (0);
	// 	str2 = malloc(sizeof(t_list));
	// 	if (!str2)
	// 		return (0);
	// 	str3 = malloc(sizeof(t_list));
	// 	if (!str3)
	// 		return (0);
	// 	list->content = strdup("a");
	// 	str1->content = strdup("b");
	// 	str2->content = strdup("c");
	// 	str3->content = strdup("d");
	// 	list->next = str1;
	// 	str1->next = str2;
	// 	str2->next = str3;
	// 	str3->next = NULL;
	// 	printf("%s\n", (char *)list->content);
	// 	printf("%s\n", (char *)str1->content);
	// 	printf("%s\n", (char *)str2->content);
	// 	printf("%s\n", (char *)str3->content);
	// 	ft_lstiter(list, &ft_plus);
	// 	printf("%s\n", (char *)list->content);
	// 	printf("%s\n", (char *)str1->content);
	// 	printf("%s\n", (char *)str2->content);
	// 	printf("%s\n", (char *)str3->content);
	// 	ft_lstclear(&list, &delete);
}