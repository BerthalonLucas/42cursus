/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:00:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/25 20:19:25 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_map(char **map, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_printf("Error");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	free_textures(t_textures *textures)
{
	if (textures->wall)
		mlx_delete_texture(textures->wall);
	if (textures->floor)
		mlx_delete_texture(textures->floor);
	if (textures->exit)
		mlx_delete_texture(textures->exit);
	if (textures->player)
		mlx_delete_texture(textures->player);
	if (textures->collectible)
		mlx_delete_texture(textures->collectible);
}

void	free_images(t_img *img, t_game *game)
{
	int i;

	i = 0;
	free_textures(game->textures);
	if (img->wall)
		mlx_delete_image(game->mlx, img->wall);
	if (img->exit)
		mlx_delete_image(game->mlx, img->exit);
	if (img->player)
		mlx_delete_image(game->mlx, img->player);
	if (img->floor)
		mlx_delete_image(game->mlx, img->floor);
	if (img->collectible)
	{
		while (i < game->player->collect)
		{
			mlx_delete_image(game->mlx, img->collectible[i]);
			i++;
		}
		free(img->collectible);
	}
}
void	free_game(t_game *game)
{
	if (game->map)
		free(game->map);
	if (game->player)
		free(game->player);
	if (game->mlx)
		free(game->mlx);
}

void	cleanup_game(t_game *game)
{
	free_images(game->img, game);
	free_textures(game->textures);
	free_game(game);
	free_map(game->map->map, game->map->height);
}