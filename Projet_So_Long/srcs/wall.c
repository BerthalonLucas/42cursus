/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:01:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/21 20:23:23 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_entries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <username@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:15:58 by username          #+#    #+#             */
/*   Updated: 2024/05/17 19:15:37 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_wall_texture(t_game *game)
{
	game->textures->wall = mlx_load_png("./textures/wall.png");
	if (!game->textures->wall)
	{
		ft_fprintf(2, "Error: Failed to load wall texture\n");
		free_textures(game->textures);
		exit(EXIT_FAILURE);
	}
	game->img->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
	if (!game->img->wall)
	{
		ft_fprintf(2, "Error: Failed to convert wall texture to image\n");
		free_images(game->img, game);
		exit(EXIT_FAILURE);
	}
}

void	place_wall(t_game *game)
{
	int	x;
	int	y;

	load_wall_texture(game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img->wall, x * 64, y * 64);
			x++;
		}
		y++;
	}
}


