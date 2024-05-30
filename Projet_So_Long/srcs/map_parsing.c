/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:27:49 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/28 23:56:32 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(t_map *map)
{
	if (!is_rectangular(map))
	{
		ft_fprintf(2, "Error: Map is not rectangular ");
		free_double_ptr(map->map, map->height);
		exit(EXIT_FAILURE);
	}
	if (!check_borders(map))
	{
		ft_fprintf(2, "Error: Map borders are invalid ");
		free_double_ptr(map->map, map->height);
		exit(EXIT_FAILURE);
	}
	if (!check_content(map))
	{
		ft_fprintf(2, "Error: Map content is invalid ");
		free_double_ptr(map->map, map->height);
		exit(EXIT_FAILURE);
	}
	if (!is_path_valid(map))
	{
		ft_fprintf(2, "Error: No valid path in the map ");
		free_double_ptr(map->map, map->height);
		exit(EXIT_FAILURE);
	}
}

void	add_line_to_map(t_map *map, char *line)
{
	int	old_height;
	int	new_height;

	old_height = map->height;
	new_height = map->height + 1;
	check_map_width_height(map);
	map->map = ft_realloc(map->map, old_height * sizeof(char *),
			new_height * sizeof(char *));
	if (map->map == NULL)
	{
		ft_fprintf(2, "Error: Memory allocation failed ");
		exit(EXIT_FAILURE);
	}
	map->map[map->height] = ft_strdup(line);
	if (map->map[map->height] == NULL)
	{
		free_double_ptr(map->map, map->height);
		ft_fprintf(2, "Error: Memory allocation failed ");
		exit(EXIT_FAILURE);
	}
	map->height++;
}

void	get_map(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		clean_newline(line);
		if (map->height == 0)
			map->width = ft_strlen(line);
		else if ((int)ft_strlen(line) != map->width)
		{
			ft_fprintf(2, "Error: Map is not rectangular ");
			free_ptr(line);
			free_double_ptr(map->map, map->height);
			exit(EXIT_FAILURE);
		}
		if (*line != '\0')
			add_line_to_map(map, line);
		free_ptr(line);
		line = get_next_line(fd);
	}
	if (map->map == NULL)
	{
		ft_fprintf(2, "Error: Invalid map ");
		exit(EXIT_FAILURE);
	}
}

int	is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->map[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	check_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
