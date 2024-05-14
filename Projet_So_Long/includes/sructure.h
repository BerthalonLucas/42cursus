/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sructure.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:13:03 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/02 17:03:51 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "so_long.h"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;




#endif