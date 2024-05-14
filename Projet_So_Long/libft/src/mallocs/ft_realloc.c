/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:34:02 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/14 19:34:51 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return ;
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free(ptr);
		ft_putstr_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	if (ptr != NULL)
	{
		ft_memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}

}

void ft_realloc_tab(void **ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(*ptr);
		*ptr = NULL;
		return ;
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free(*ptr);
		ft_putstr_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	if (*ptr != NULL)
	{
		ft_memcpy(new_ptr, *ptr, old_size);
		free(*ptr);
	}
	*ptr = new_ptr;
}

