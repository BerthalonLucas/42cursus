/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:49:00 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/23 03:57:54 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;
	mlx_image_t *instance;

	new_x = game->player->x + dx;
	new_y = game->player->y + dy;
	if (game->map->map[new_y / SIZE][new_x / SIZE] == '1')
		return ;
	if (game->map->map[new_y / SIZE][new_x / SIZE] == 'E')
	{
		if (game->player->collect == 0)
		{
			mlx_terminate(game->mlx);
			printf("You won\n");
			exit(EXIT_SUCCESS);
		}
	}
	if (game->map->map[new_y / SIZE][new_x / SIZE] == 'C')
	{
		game->map->map[new_y / SIZE][new_x / SIZE] = '0';
		instance = find_collect_instance(game, new_x, new_y);
		instance->enabled = false;
		game->player->collect--;
	}
	if (dx)
	{
		game->img->player->instances->x = new_x;
		game->player->x = new_x;
	}
	if (dy)
	{
		game->img->player->instances->y = new_y;
		game->player->y = new_y;
	}
}
