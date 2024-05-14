#include "../includes/so_long.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_map	map;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Usage: %s <file.ber>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Failed to open file\n");
		return (1);
	}
	get_map(&map, fd);
	print_map(&map);
	check_map(&map);
	free_map(map.map, map.height);
	close(fd);
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




// int main(int ac, char **av)
// {
// 	t_map map;
// 	int fd;

// 	if (ac != 2)
// 	{
// 		printf("Error\n");
// 		return (0);
// 	}
// 	ft_bzero(&map, sizeof(t_map));
// 	fd = open(av[1], O_RDONLY);
// 	get_map(&map, fd);
// 	check_map(&map);
// 	free_map(&map);
// 	close(fd);
// 	return (0);
// }


// int main(void)
// {
// 	mlx_t *mlx;
// 	mlx_texture_t *img;
// 	mlx_texture_t *mur;
// 	// mlx_image_t *img2;
// 	mlx_image_t *grass2;
// 	int x;
// 	int y;

// 	x =	0;
// 	y = 0;
// 	mlx = mlx_init(1920, 1080, "MLX42", true);
// 	if (!mlx)
// 	{
// 		printf("Error\n");
// 		return (0);
// 	}
// 	img = mlx_load_png("/home/lberthal/Desktop/repogit/Projet_So_Long/MLX/docs/assets/logo.png");
// 	mur = mlx_load_png("/home/lberthal/Desktop/repogit/Projet_So_Long/textures/128x128/Bricks/Bricks_01-128x128.png");
// 	grass2 = mlx_texture_to_image(mlx, mur);
// 	// img2 = mlx_texture_to_image(mlx, img);
// 	while (y < 4)
// 	{
// 		x = 0;
// 		while (x < 4)
// 		{
// 			mlx_image_to_window(mlx, grass2, x, y);
// 			x += 1;
// 		}
// 		y += 1;
// 	}
// 	mlx_set_icon(mlx, img);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (0);
// } 