/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:34:02 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/28 00:59:35 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free_ptr(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free_ptr(ptr);
		ft_putstr_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	if (ptr != NULL)
	{
		ft_memcpy(new_ptr, ptr, old_size);
		free_ptr(ptr);
	}
	return (new_ptr);
}
