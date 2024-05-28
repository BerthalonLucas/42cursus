/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:02:03 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/27 23:45:19 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	place_floor(t_game *game)
{
	int	x;
	int	y;

	load_floor_texture(game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			mlx_image_to_window(game->mlx, game->img->floor, x * SIZE, y
				* SIZE);
			x++;
		}
		y++;
	}
}

void	load_floor_texture(t_game *game)
{
	if (!game->textures->floor)
	{
		game->textures->floor = mlx_load_png("./textures/floor2.png");
		if (!game->textures->floor)
		{
			ft_fprintf(2, "Error: Failed to load floor texture\n");
			free_textures(game->textures);
			exit(EXIT_FAILURE);
		}
		game->img->floor = mlx_texture_to_image(game->mlx,
				game->textures->floor);
		if (!game->img->floor)
		{
			ft_fprintf(2, "Error: Failed to convert floor texture to image\n");
			free_images(game->img, game);
			exit(EXIT_FAILURE);
		}
	}
}
