/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:18:41 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/23 00:04:16 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

void	place_exit(t_game *game)
{
	int	x;
	int	y;

	load_exit_texture(game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img->exit, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

void	load_exit_texture(t_game *game)
{
	if (!game->textures->exit)
	{
		game->textures->exit = mlx_load_png("./textures/exit.png");
		if (!game->textures->exit)
		{
			ft_fprintf(2, "Error: Failed to load exit texture\n");
			free_textures(game->textures);
			exit(EXIT_FAILURE);
		}
		game->img->exit = mlx_texture_to_image(game->mlx, game->textures->exit);
		if (!game->img->exit)
		{
			ft_fprintf(2, "Error: Failed to convert exit texture to image\n");
			free_images(game->img, game);
			exit(EXIT_FAILURE);
		}
	}
}