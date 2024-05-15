/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:49:00 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/15 04:55:36 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

void find_player(t_player *player, char **map)
{
    int y;
    int x;

    y = 0;
	player->x = 0;
	player->y = 0;
	player->move_count = 0;
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            if (map[y][x] == 'P')
            {
                player->x = x;
                player->y = y;
				map[y][x] = '0';
                return ;
            }
            x++;
        }
        y++;
    }
}

void move_player(t_player *player, char **map, int dx, int dy)
{
	int new_x;
	int new_y;
	char cell;

	new_x = player->x + dx;
	new_y = player->y + dy;
	cell = map[new_y][new_x];
	if (cell == '1')
		return ;
	if (cell == 'C')
	{
		player->collect++;
		map[new_y][new_x] = '0';
	}
	player->x = new_x;
	player->y = new_y;
}

