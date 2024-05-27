/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:02:01 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/27 22:07:44 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	place_collectibles(t_game *game)
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
				mlx_image_to_window(game->mlx, game->img->clt[i], x * SIZE, y
					* SIZE);
				game->img->clt[i]->instances->x = x * SIZE;
				game->img->clt[i]->instances->y = y * SIZE;
				i--;
			}
			x++;
		}
		y++;
	}
}

void	load_collectible_texture(t_game *game)
{
	if (!game->textures->clt)
	{
		collectibles_count(game);
		game->textures->clt = mlx_load_png("./textures/collect.png");
		if (!game->textures->clt)
		{
			ft_fprintf(2, "Error: Failed to load collectible texture\n");
			free_textures(game->textures);
			exit(EXIT_FAILURE);
		}
		tab_collect(game);
	}
}

void	collectibles_count(t_game *game)
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

void	tab_collect(t_game *game)
{
	int	count;

	count = game->player->collect;
	game->img->clt = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (!game->img->clt)
	{
		ft_fprintf(2, "Error: Failed to allocate memory for collectibles\n");
		free_textures(game->textures);
		exit(EXIT_FAILURE);
	}
	game->img->clt[count] = NULL;
	while (--count)
	{
		game->img->clt[count] = mlx_texture_to_image(game->mlx,
				game->textures->clt);
		if (!game->img->clt[count])
		{
			ft_fprintf(2,
				"Error: Failed to convert collectible texture to image\n");
			free_images(game->img, game);
			exit(EXIT_FAILURE);
		}
	}
}

mlx_image_t	*find_collect_instance(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (game->img->clt[i])
	{
		if (game->img->clt[i]->instances->x == x
			&& game->img->clt[i]->instances->y == y)
			return (game->img->clt[i]);
		i++;
	}
	return (NULL);
}
