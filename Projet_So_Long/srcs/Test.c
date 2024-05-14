#include "../includes/so_long.h"
#include <stdio.h>

int main(void)
{
	mlx_t *mlx;
	mlx_texture_t *img;
	mlx_texture_t *mur;
	// mlx_image_t *img2;
	mlx_image_t *grass2;
	int x;
	int y;

	x =	0;
	y = 0;
	mlx = mlx_init(1920, 1080, "MLX42", true);
	if (!mlx)
	{
		printf("Error\n");
		return (0);
	}
	img = mlx_load_png("/home/lberthal/Desktop/repogit/Projet_So_Long/MLX/docs/assets/logo.png");
	mur = mlx_load_png("/home/lberthal/Desktop/repogit/Projet_So_Long/textures/128x128/Bricks/Bricks_01-128x128.png");
	grass2 = mlx_texture_to_image(mlx, mur);
	// img2 = mlx_texture_to_image(mlx, img);
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			mlx_image_to_window(mlx, grass2, x, y);
			x += 1;
		}
		y += 1;
	}
	mlx_set_icon(mlx, img);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
} 