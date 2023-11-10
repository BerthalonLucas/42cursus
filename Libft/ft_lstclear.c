/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:13:52 by lberthal          #+#    #+#             */
/*   Updated: 2023/11/09 22:49:02 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *next;
	
	if (!lst || !del)
		return;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		del(temp->content);
		free(temp);
		temp = next;
	}
	*lst = NULL;
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
// }