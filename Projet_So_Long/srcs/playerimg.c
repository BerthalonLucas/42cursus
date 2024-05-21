/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerimg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:01:54 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/21 21:07:15 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	place_player(t_game *game)
{
	int	x;
	int	y;

	load_player_texture(game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img->player, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
void load_player_texture(t_game *game)
{
	if (!game->textures->player)
	{
		game->textures->player = mlx_load_png("./textures/player.png");
		if (!game->textures->player)
		{
			ft_fprintf(2, "Error: Failed to load player texture\n");
			free_textures(game->textures);
			exit(EXIT_FAILURE);
		}
		game->img->player = mlx_texture_to_image(game->mlx, game->textures->player);
		if (!game->img->player)
		{
			ft_fprintf(2, "Error: Failed to convert player texture to image\n");
			free_images(game->img, game);
			exit(EXIT_FAILURE);
		}
	}
}