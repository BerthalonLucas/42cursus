/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:36:38 by lucas             #+#    #+#             */
/*   Updated: 2024/05/15 03:18:24 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX/include/MLX42/MLX42.h"
# include "struct.h"
# include <fcntl.h>
# include <stdio.h>

int	is_rectangular(t_map *map);
int	check_borders(t_map *map);
int	check_content(t_map *map);
void	mark_accessible(char **map, int x, int y);
int	is_path_valid_P_C(t_map *map);
void	check_map(t_map *map);
void	get_map(t_map *map, int fd);

void	*safe_malloc(size_t size);
void	free_map(char **map, int height);
void	print_map(t_map *map);
void	clean_newline(char *line);
int is_path_valid_C(t_map *map);

#endif