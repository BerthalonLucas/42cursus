/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:41:36 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/28 02:55:05 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_content(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			verif_content(map, j, i);
			i++;
		}
		j++;
	}
	if (map->player_count == 1 && map->exit_count == 1
		&& map->collectible_count >= 1 && map->verif == 1)
		map->verif = 1;
	else
		map->verif = 0;
	return (map->verif);
}

void	verif_content(t_map *map, int j, int i)
{
	if (map->map[j][i] == 'P')
		map->player_count++;
	else if (map->map[j][i] == 'E')
		map->exit_count++;
	else if (map->map[j][i] == 'C')
		map->collectible_count++;
	if (map->map[j][i] != 'P' && map->map[j][i] != 'E' && map->map[j][i] != 'C'
		&& map->map[j][i] != '1' && map->map[j][i] != '0')
		map->verif = 0;
}

void	mark_accessible(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	mark_accessible(map, x + 1, y);
	mark_accessible(map, x - 1, y);
	mark_accessible(map, x, y + 1);
	mark_accessible(map, x, y - 1);
}

int	is_path_valid_p(t_map *map)
{
	int		i;
	int		j;
	char	**copy;

	copy = ft_map_copy(map->map, map->height);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (copy[i][j] == 'P')
			{
				mark_accessible(copy, j, i);
				break ;
			}
			j++;
		}
		if (j < map->width)
			break ;
		i++;
	}
	i = find_x(map, copy);
	free_double_ptr(copy, map->height);
	return (i);
}

int	is_path_valid_c(t_map *map)
{
	int		i;
	int		j;
	char	**copy;

	copy = ft_map_copy(map->map, map->height);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (copy[i][j] == 'C')
			{
				mark_accessible(copy, j, i);
				break ;
			}
			j++;
		}
		if (j < map->width)
			break ;
		i++;
	}
	i = find_x(map, copy);
	free_double_ptr(copy, map->height);
	return (i);
}
