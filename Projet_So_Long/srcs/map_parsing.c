/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:27:49 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/25 20:34:03 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangular(t_map *map)
{
	int i;

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
	int i;

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
int	check_content(t_map *map)
{
	int i;
	int j;
	int player_count;
	int exit_count;
	int collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->map[j][i] == 'P')
				player_count++;
			else if (map->map[j][i] == 'E')
				exit_count++;
			else if (map->map[j][i] == 'C')
				collectible_count++;
			i++;
		}
		j++;
	}
	return (player_count == 1 && exit_count == 1 && collectible_count >= 1);
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

char **ft_map_copy(char **map, int height)
{
	char	**copy;
	int		i;

	copy = (char **)safe_malloc(height * sizeof(char *));
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (copy[i] == NULL)
		{
			free_map(copy, i);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

int	is_path_valid_P_C(t_map *map)
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
	free_map(copy, map->height);
	if (!is_path_valid_C(map))
		return (0);
	return (1);
}
int is_path_valid_C(t_map *map)
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
	free_map(copy, map->height);
	return (1);
}

void	check_map(t_map *map)
{
	if (!is_rectangular(map))
	{
		ft_fprintf(2, "Error: Map is not rectangular ");
		free_map(map->map, map->height);
		exit(EXIT_FAILURE);
	}
	if (!check_borders(map))
	{
		ft_fprintf(2, "Error: Map borders are invalid ");
		free_map(map->map, map->height);
		exit(EXIT_FAILURE);
	}
	if (!check_content(map))
	{
		ft_fprintf(2, "Error: Map content is invalid ");
		free_map(map->map, map->height);
		exit(EXIT_FAILURE);
	}
	if (!is_path_valid_P_C(map))
	{
		ft_fprintf(2, "Error: No valid path in the map ");
		free_map(map->map, map->height);
		exit(EXIT_FAILURE);
	}
}

void	add_line_to_map(t_map *map, char *line)
{
	int old_height;
	int new_height;

	old_height = map->height * sizeof(char *);
	new_height = (map->height + 1) * sizeof(char *);
	map->map = ft_realloc(map->map, old_height, new_height);
	map->map[map->height] = ft_strdup(line);
	if (map->map[map->height] == NULL)
	{
		free_map(map->map, map->height);
		ft_fprintf(2, "Error");
		exit(EXIT_FAILURE);
	}
	map->height++;
}
void	clean_newline(char *line)
{
	size_t len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	get_map(t_map *map, int fd)
{
	char	*line;

	map->map = NULL;
	map->height = 0;
	map->width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		clean_newline(line);
		if (map->height == 0)
			map->width = ft_strlen(line);
		else if ((int)ft_strlen(line) != map->width)
		{
			ft_fprintf(2, "Error: Map is not rectangular ");
			free(line);
			free_map(map->map, map->height);
			exit(EXIT_FAILURE);
		}
		if (*line != '\0')
			add_line_to_map(map, line);
		free(line);
	}
	if (map->map == NULL)
	{
		ft_fprintf(2, "Error: Invalid map ");
		exit(EXIT_FAILURE);
	}
}
