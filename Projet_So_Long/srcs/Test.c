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
	if (!(fd = check_fd(argv[1])))
		return (0);
	init_game(&game);
	get_map(game.map, fd);
	close(fd);
	print_map(game.map);
	check_map(game.map);
	mlx_start(&game);
	mlx_terminate(game.mlx);
	cleanup_game(&game);
	return (0);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
}

int check_fd(char *path)
{
	int fd;
	char *res;

	res = ft_strnstr(path, ".ber", 4);
	ft_printf("%s", path);
	if (ft_strncmp(".ber", res, 4) == 0)
	{
		ft_fprintf(2, "Error: Failed find .ber file\n");
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_fprintf(2, "Error: Failed to open file\n");
		return (0);
	}
	return (fd);
}
