/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:25:44 by lberthal          #+#    #+#             */
/*   Updated: 2023/11/10 01:24:30 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*content;

	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_elem = ft_lstnew(content);
		if (!new_elem)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
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
// }