/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_entries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:15:58 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/30 04:57:02 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

void	mlx_start(t_game *game)
{
	game->mlx = mlx_init(game->map->width * SIZE, game->map->height * SIZE,
			"So Long", true);
	if (!game->mlx)
	{
		ft_fprintf(2, "Error: init MiniLibX\n");
		exit(EXIT_FAILURE);
	}
	display_map(game);
	game->map->width *= SIZE;
	game->map->height *= SIZE;
	mlx_key_hook(game->mlx, handle_keypress, game);
	mlx_close_hook(game->mlx, close_game, game);
	mlx_loop(game->mlx);
}

void	display_map(t_game *game)
{
	place_floor(game);
	place_wall(game);
	place_exit(game);
	place_player(game);
	place_collectibles(game);
}

void	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	cleanup_game(game);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
