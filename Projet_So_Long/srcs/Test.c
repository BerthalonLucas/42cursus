#include "../includes/so_long.h"
#include <stdio.h>
#include <mlx.h>

int main(void)
{
	void *mlx;
	// void *win;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("Error\n");
		return (0);
	}
	// win = mlx_new_window(mlx, 500, 500, "Hello World!");
	// mlx_loop(mlx);
	return (0);
}