/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:18:57 by lberthal          #+#    #+#             */
/*   Updated: 2023/11/07 16:12:36 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	 new->next = *lst;
}

// int main(void)
// {
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
// }