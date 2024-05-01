#include "../includes/so_long.h"
#include <stdio.h>

int main(void)
{
	void *mlx;
	// void *win;

	mlx = mlx_init(1920, 1080, "MLX42", true);
	if (!mlx)
	{
		printf("Error\n");
		return (0);
	}
	// win = mlx_new_window(mlx, 500, 500, "Hello World!");
	mlx_loop(mlx);
	return (0);
}