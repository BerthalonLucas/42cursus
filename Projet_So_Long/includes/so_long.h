/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:36:38 by lucas             #+#    #+#             */
/*   Updated: 2024/05/27 01:50:49 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX/include/MLX42/MLX42.h"
# include "struct.h"
# include <fcntl.h>
# include <stdio.h>
#include <unistd.h>

# define SIZE 64

int	is_rectangular(t_map *map);
int	check_borders(t_map *map);
int	check_content(t_map *map);
void	mark_accessible(char **map, int x, int y);
int	is_path_valid_P(t_map *map);
void	check_map(t_map *map);
void	get_map(t_map *map, int fd);
void	*safe_malloc(size_t size);
void	free_map(char **map, int height);
void	print_map(char **map);
void	clean_newline(char *line);
int is_path_valid_C(t_map *map);
void	move_player(t_game *game, int dx, int dy);
void	free_textures(t_textures *textures);
void	free_images(t_img *img, t_game *game);
void	mlx_start(t_game *game);
void	init_game(t_game *game);
void	load_wall_texture(t_game *game);
void	place_wall(t_game *game);
void	place_floor(t_game *game);
void	load_floor_texture(t_game *game);
void	cleanup_game(t_game *game);
void display_map(t_game *game);
void	place_exit(t_game *game);
void	load_exit_texture(t_game *game);
void	place_player(t_game *game);
void load_player_texture(t_game *game);
void	place_collectibles(t_game *game);
void load_collectible_texture(t_game *game);
void handle_keypress(void *param);
void my_usleep(double seconds);
void collectibles_count(t_game *game);
void tab_collect(t_game *game);
mlx_image_t *find_collect_instance(t_game *game, int x, int y);
void init_each(t_game *game);
int check_fd(char *path);
int check_fd(char *filename);
int check_filename(char *filename);
void handle_movement(t_game *game, double *last_move_time, double current_time);
void handle_escape(t_game *game);
void verif_content(t_map *map, int j, int i);
int find_X(t_map *map, char **mapi);
int is_path_valid(t_map *map);
void check_map_width_height(t_map *map);
void close_game(void *param);
char **ft_map_copy(char **map, int height);


#endif