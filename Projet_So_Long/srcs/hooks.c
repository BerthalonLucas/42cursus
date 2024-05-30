/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:58:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/30 00:30:09 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_keypress(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		handle_escape(game);
	if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		move_player(game, 0, -SIZE);
	if (key.key == MLX_KEY_W && key.action == MLX_REPEAT)
		move_player(game, 0, -SIZE);
	if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		move_player(game, -SIZE, 0);
	if (key.key == MLX_KEY_A && key.action == MLX_REPEAT)
		move_player(game, -SIZE, 0);
	if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		move_player(game, 0, SIZE);
	if (key.key == MLX_KEY_S && key.action == MLX_REPEAT)
		move_player(game, 0, SIZE);
	if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		move_player(game, SIZE, 0);
	if (key.key == MLX_KEY_D && key.action == MLX_REPEAT)
		move_player(game, SIZE, 0);
	handle_arrow(key, game);
}

void	handle_arrow(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		move_player(game, 0, -SIZE);
	if (key.key == MLX_KEY_UP && key.action == MLX_REPEAT)
		move_player(game, 0, -SIZE);
	if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		move_player(game, -SIZE, 0);
	if (key.key == MLX_KEY_LEFT && key.action == MLX_REPEAT)
		move_player(game, -SIZE, 0);
	if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		move_player(game, 0, SIZE);
	if (key.key == MLX_KEY_DOWN && key.action == MLX_REPEAT)
		move_player(game, 0, SIZE);
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		move_player(game, SIZE, 0);
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_REPEAT)
		move_player(game, SIZE, 0);
}

void	handle_escape(t_game *game)
{
	mlx_close_window(game->mlx);
	exit(EXIT_SUCCESS);
}
