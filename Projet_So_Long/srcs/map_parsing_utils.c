/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:40:00 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/27 02:31:03 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

void check_map_width_height(t_map *map)
{
	if (map->width > 48 || map->height > 48)
	{
		ft_fprintf(2, "Error: Map is too big ");
		free_double_ptr(map->map);
		exit(EXIT_FAILURE);
	}
}

void	clean_newline(char *line)
{
	size_t len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int find_X(t_map *map, char **mapi)
{
	int i;
	int j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (mapi[j][i] == 'E' || mapi[j][i] == 'C' || mapi[j][i] == 'P')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
int is_path_valid(t_map *map)
{
	if (!is_path_valid_P(map))
		return (0);
	if (!is_path_valid_C(map))
		return (0);
	return (1);
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
			free_double_ptr(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}