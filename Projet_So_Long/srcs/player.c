/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:49:00 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/21 21:13:13 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x + dx;
	new_y = game->player->y + dy;

	if (new_x >= 0 && new_x < game->map->width &&
		new_y >= 0 && new_y < game->map->height &&
		game->map->map[new_y][new_x] != '1')
	{
		mlx_image_to_window(game->mlx, game->img->floor, game->player->x * 64, game->player->y * 64);
		game->player->x = new_x;
		game->player->y = new_y;
		place_player(game);
	}
}

