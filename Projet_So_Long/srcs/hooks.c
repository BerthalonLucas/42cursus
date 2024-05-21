/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:58:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/21 22:23:17 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

void handle_keypress(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_player(game, 0, -1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_player(game, 0, 1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_player(game, -1, 0);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move_player(game, 1, 0);
}
