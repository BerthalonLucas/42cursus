/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:58:43 by lberthal          #+#    #+#             */
/*   Updated: 2023/11/07 17:08:58 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main(void)
// {
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
// }