/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:03:46 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/26 02:36:54 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->map = safe_malloc(sizeof(t_map));
	game->player = safe_malloc(sizeof(t_player));
	game->textures = safe_malloc(sizeof(t_textures));
	game->img = safe_malloc(sizeof(t_img));
	init_each(game);
}

void	init_each(t_game *game)
{
	ft_bzero(game->map, sizeof(t_map));
	game->map->verif = 1;
	ft_bzero(game->player, sizeof(t_player));
	ft_bzero(game->textures, sizeof(t_textures));
	ft_bzero(game->img, sizeof(t_img));
}
