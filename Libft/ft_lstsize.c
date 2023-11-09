/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:13:33 by lberthal          #+#    #+#             */
/*   Updated: 2023/11/09 01:09:18 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int i;
	
	if (!lst)
		return;
	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
// 	printf("%d\n", ft_lstsize(list));
// 	free(list);
// 	free(str1);
// 	free(str2);
// 	free(str3);
// }