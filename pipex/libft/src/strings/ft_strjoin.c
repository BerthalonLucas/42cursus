/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:32:04 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/03 05:24:33 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lens = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * lens);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, lens);
	ft_strlcat(str, s2, lens);
	return (str);
}
