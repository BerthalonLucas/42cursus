/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:02:01 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/21 21:05:56 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	place_collectibles(t_game *game)
{
	int	x;
	int	y;

	load_collectible_texture(game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img->collectible, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
void load_collectible_texture(t_game *game)
{
	if (!game->textures->collectible)
	{
		game->textures->collectible = mlx_load_png("./textures/collect.png");
		if (!game->textures->collectible)
		{
			ft_fprintf(2, "Error: Failed to load collectible texture\n");
			free_textures(game->textures);
			exit(EXIT_FAILURE);
		}
		game->img->collectible = mlx_texture_to_image(game->mlx, game->textures->collectible);
		if (!game->img->collectible)
		{
			ft_fprintf(2, "Error: Failed to convert collectible texture to image\n");
			free_images(game->img, game);
			exit(EXIT_FAILURE);
		}
	}
}