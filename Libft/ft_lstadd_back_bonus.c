/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:54 by lberthal          #+#    #+#             */
/*   Updated: 2023/11/07 17:38:06 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;
	
	temp = lst[0];
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
}
int main(void)
{
	t_list **list;
	t_list	*str1;
	t_list	*str2;
	t_list	*str3;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	list = malloc(sizeof(t_list));
	if (!list)
		return (0);
	str1 = malloc(sizeof(t_list));
	if (!str1)
		return (0);
	str2 = malloc(sizeof(t_list));
	if (!str2)
		return (0);
	str3 = malloc(sizeof(t_list));
	if (!str3)
		return (0);
	list[0]->next = str1;
	str1->next = str2;
	str2->next = str3;
	str3->next = NULL;
	printf("%d\n", ft_lstsize(list));
	ft_lstadd_back(list, new);
	printf("%d\n", ft_lstsize(list));
	free(list);
	free(str1);
	free(str2);
	free(str3);
	free(new);
}