/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:36:38 by lucas             #+#    #+#             */
/*   Updated: 2024/05/14 20:07:52 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "struct.h"
# include "../MLX/include/MLX42/MLX42.h"
# include <fcntl.h>

int	is_rectangular(t_map *map);
int	check_borders(t_map *map);
int	check_content(t_map *map);
void	mark_accessible(char **map, int x, int y);
int	is_path_valid(t_map *map);
void	check_map(t_map *map);
void	get_map(t_map *map, int fd);

void	*safe_realloc(void *ptr, size_t old_size, size_t new_size);
void	*safe_malloc(size_t size);
void	free_map(char **map, int height);
void	print_map(t_map *map);
void	clean_newline(char *line);

#endif