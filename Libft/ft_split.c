/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:11:28 by lucas             #+#    #+#             */
/*   Updated: 2023/11/08 21:00:56 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t word_count(const char *str, char delimiter);
static void *free_tab(char **tab, size_t index);
static char *allocate_word(const char *start, size_t len);

static size_t word_count(const char *str, char delimiter)
{
	size_t count;
	const char *ptr;

	count = 0;
	ptr = str;
	while (*ptr)
	{
		while (*ptr && *ptr == delimiter)
			ptr++;
		if (*ptr && *ptr != delimiter)
		{
			count++;
			while (*ptr && *ptr != delimiter)
				ptr++;
		}
	}
	return (count);
}

static void *free_tab(char **tab, size_t index)
{
	size_t i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char *allocate_word(const char *start, size_t len)
{
	char *word;
	size_t i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char **ft_split(char const *s, char c)
{
	char **tab;
	size_t i;
	size_t count;
	const char *word_start;

	count = word_count(s, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		word_start = s;
		while (*s && *s != c)
			s++;
		tab[i] = allocate_word(word_start, s - word_start);
		if (tab[i] == NULL)
			return (free_tab(tab, i));
		i++;
	}
	tab[count] = (NULL);
	return (tab);
}
// int main(void)
// {
// 	int i = 0;
// 	// char *str = "    lyigk iugvuvhj";
// 	// char *str = "123456789";
// 	// char *str = "545  516     651   ";
// 	char *str = "xxxxxxxxhello!";
// 	char c = 'x';
// 	char **tab;

// 	tab = ft_split(str, c);
// 	while (tab[i] != NULL)
// 	{
// 		if (tab == NULL)
// 			return (printf("fonction NULL for STR"));
// 		if (tab[i] == NULL)
// 		{
// 			printf("String, NULL for STR\n");
// 			return (0);
// 		}
// 		else
// 			printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	ft_free(tab, i);
// }