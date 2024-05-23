/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:02:01 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/23 03:52:35 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void place_collectibles(t_game *game)
{
	int	x;
	int	y;
	int	i;

	load_collectible_texture(game);
	i = game->player->collect - 1;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx, game->img->collectible[i], x * SIZE, y * SIZE);
				game->img->collectible[i]->instances->x = x * SIZE;
				game->img->collectible[i]->instances->y = y * SIZE;
				i--;
			}
			x++;
		}
		y++;
	}

}
void load_collectible_texture(t_game *game)
{
	if (!game->textures->collectible)
	{
		collectibles_count(game);
		game->textures->collectible = mlx_load_png("./textures/collect.png");
		if (!game->textures->collectible)
		{
			ft_fprintf(2, "Error: Failed to load collectible texture\n");
			free_textures(game->textures);
			exit(EXIT_FAILURE);
		}
		tab_collect(game);
	}
}

void collectibles_count(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'C')
				game->player->collect++;
			x++;
		}
		y++;
	}
}

void tab_collect(t_game *game)
{
	int			count;

	count = game->player->collect;
	game->img->collectible = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (!game->img->collectible)
	{
		ft_fprintf(2, "Error: Failed to allocate memory for collectibles\n");
		free_textures(game->textures);
		exit(EXIT_FAILURE);
	}
	game->img->collectible[count] = NULL;
	while (count)
	{
		game->img->collectible[count - 1] = mlx_texture_to_image(game->mlx, game->textures->collectible);
		if (!game->img->collectible[count - 1])
		{
			ft_fprintf(2, "Error: Failed to convert collectible texture to image\n");
			free_images(game->img, game);
			exit(EXIT_FAILURE);
		}
		count--;
	}
}

mlx_image_t *find_collect_instance(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (game->img->collectible[i])
	{
		if (game->img->collectible[i]->instances->x == x &&
		 game->img->collectible[i]->instances->y == y)
			return (game->img->collectible[i]);
		i++;
	}
	return (NULL);
}