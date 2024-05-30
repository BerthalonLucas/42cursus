/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:49:00 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/30 04:57:38 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int			new_x;
	int			new_y;

	new_x = game->player->x + dx;
	new_y = game->player->y + dy;
	if (game->map->map[new_y / SIZE][new_x / SIZE] == '1')
		return ;
	check_exit(game, new_x, new_y);
	if_collectible(game, new_x, new_y);
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
	game->player->move_count++;
	ft_printf("Moves: %d\n", game->player->move_count);
}

void	check_exit(t_game *game, int new_x, int new_y)
{
	if (game->map->map[new_y / SIZE][new_x / SIZE] == 'E')
	{
		if (game->player->collect == 0)
		{
			mlx_terminate(game->mlx);
			ft_printf("You won\n");
			exit(EXIT_SUCCESS);
		}
	}
}

void	if_collectible(t_game *game, int new_x, int new_y)
{
	mlx_image_t	*instance;

	if (game->map->map[new_y / SIZE][new_x / SIZE] == 'C')
	{
		game->map->map[new_y / SIZE][new_x / SIZE] = '0';
		instance = find_collect_instance(game, new_x, new_y);
		instance->enabled = false;
		game->player->collect--;
	}
}
