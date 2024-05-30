/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:00:50 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/30 04:57:19 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (textures->clt)
		mlx_delete_texture(textures->clt);
}

void	free_images(t_img *img, t_game *game)
{
	int	i;

	i = 0;
	if (img->wall)
		mlx_delete_image(game->mlx, img->wall);
	if (img->exit)
		mlx_delete_image(game->mlx, img->exit);
	if (img->player)
		mlx_delete_image(game->mlx, img->player);
	if (img->floor)
		mlx_delete_image(game->mlx, img->floor);
	if (img->clt)
	{
		while (i < game->player->collect)
		{
			mlx_delete_image(game->mlx, img->clt[i]);
			i++;
		}
		free_ptr(img->clt);
	}
}

void	free_game(t_game *game)
{
	if (game->map)
		free_ptr(game->map);
	if (game->player)
		free_ptr(game->player);
	if (game->mlx)
		mlx_close_window(game->mlx);
}

void	cleanup_game(t_game *game)
{
	free_images(game->img, game);
	free_textures(game->textures);
	free_double_ptr(game->map->map, game->map->height / SIZE);
	free_game(game);
}
