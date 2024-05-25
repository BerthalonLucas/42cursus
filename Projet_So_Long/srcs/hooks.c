/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:58:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/25 19:47:02 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

void handle_keypress(void *param)
{
	t_game *game;
	static double last_move_time;
	double current_time;

	game = (t_game *)param;
	last_move_time = 0;
	current_time = mlx_get_time();
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		exit(EXIT_SUCCESS);
	}

	if (current_time - last_move_time >= 0.3)
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		{
			move_player(game, 0, -SIZE);
			printf("UP\n");
			last_move_time = current_time;
			// my_usleep(0.3);
		}
		else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		{
			move_player(game, 0, SIZE);
			printf("DOWN\n");
			last_move_time = current_time;
			// my_usleep(0.3);
		}
		else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		{
			move_player(game, -SIZE, 0);
			printf("LEFT\n");
			last_move_time = current_time;
			// my_usleep(0.3);
		}
		else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		{
			move_player(game, SIZE, 0);
			printf("RIGHT\n");
			last_move_time = current_time;
			// my_usleep(0.3);
		}
	}
}

void my_usleep(double seconds)
{
	double start_time = mlx_get_time();
	while ((mlx_get_time() - start_time) < seconds)
	{

	}
}

