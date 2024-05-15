/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:58:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/15 05:02:34 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

int  MLX_KEY_hook(int  keycode, t_player *player, t_map *map)
{
    if ( keycode ==  MLX_KEY_W ||  keycode ==  MLX_KEY_UP)
        move_player(player, map, 0, -1);
    if ( keycode ==  MLX_KEY_S ||  keycode ==  MLX_KEY_DOWN)
        move_player(player, map, 0, 1);
    if ( keycode ==  MLX_KEY_A ||  keycode ==  MLX_KEY_LEFT)
        move_player(player, map, -1, 0);
    if ( keycode ==  MLX_KEY_D ||  keycode ==  MLX_KEY_RIGHT)
        move_player(player, map, 1, 0);
    return (0);
}
