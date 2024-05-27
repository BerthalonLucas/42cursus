/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:12:53 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/27 22:14:41 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Usage: %s <%s>\n", argv[0], argv[1]);
		return (1);
	}
	if (!check_filename(argv[1]))
		return (1);
	fd = check_fd(argv[1]);
	if (fd == 0)
		return (1);
	init_game(&game);
	get_map(game.map, fd);
	close(fd);
	check_map(game.map);
	mlx_start(&game);
	mlx_terminate(game.mlx);
	cleanup_game(&game);
	return (0);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int	check_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_fprintf(2, "Error: Could not open file\n");
		return (0);
	}
	return (fd);
}

int	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 4] != '.' || filename[i - 3] != 'b'
		|| filename[i - 2] != 'e' || filename[i - 1] != 'r')
	{
		ft_fprintf(2, "Error: Invalid file extension\n");
		return (0);
	}
	return (1);
}
