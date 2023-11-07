/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:54:44 by lberthal          #+#    #+#             */
/*   Updated: 2023/11/07 14:18:02 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// int main(void)
// {
// 	int i;
// 	t_list *test;
	
// 	i = 14;
// 	test = ft_lstnew(&i);
// 	printf("%d\n", *((int *)(test->content)));
// }