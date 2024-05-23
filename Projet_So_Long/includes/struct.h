/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:13:03 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/23 03:03:39 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# define NUM_TEXTURES 5
typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	move_count;
	int collect;
}	t_player;

typedef struct s_textures
{
	mlx_texture_t   *wall;
	mlx_texture_t   *exit;
	mlx_texture_t   *player;
	mlx_texture_t   *floor;
	mlx_texture_t   *collectible;
}   t_textures;

typedef struct s_img
{
	mlx_image_t     *wall;
	mlx_image_t     *exit;
	mlx_image_t     *player;
	mlx_image_t     *floor;
	mlx_image_t     **collectible;
}   t_img;

typedef struct s_game
{
	t_map 		*map;
	t_player 	*player;
	t_textures 	*textures;
	mlx_t		*mlx;
	t_img		*img;
	int			frame;
}	t_game;



#endif