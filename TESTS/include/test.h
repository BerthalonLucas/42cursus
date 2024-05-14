/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 07:11:15 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/08 06:42:54 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int 			value;
	struct s_list 	*next;
}	t_list;

t_list *lst_new(t_list *list, int value);
void free_list(t_list *list);
void add_av(t_list *list, char **av, int ac);
void	ft_lstadd_back(t_list **lst, t_list *new);



#endif