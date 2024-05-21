/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:03:46 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/21 20:10:22 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->map = safe_malloc(sizeof(t_map));
	game->player = safe_malloc(sizeof(t_player));
	game->textures = safe_malloc(sizeof(t_textures));
	game->img = safe_malloc(sizeof(t_img));
}
