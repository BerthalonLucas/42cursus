/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:34:02 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/14 02:09:53 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char			*new;
	char			*temp;
	unsigned int	i;

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
		return (free(ptr), NULL);
	new = malloc(new_size);
	if (new == NULL)
		return (NULL);
	if (new_size < old_size)
		old_size = new_size;
	temp = ptr;
	i = 0;
	while (i++ < old_size)
		*(new + i) = *(temp + i);
	return (free(ptr), new);
}
