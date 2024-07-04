#include "cubed.h"
#include "parser.h"

void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	ft_go(t_cube *map)
{
	mlx_t *mlx;
	(void)map;

	printf("Ha entrado en ft_go\n");
	mlx_set_setting(MLX_MAXIMIZED, true);
	printf("Settings creados\n");
	mlx = mlx_init(WIDTH, HEIGHT, "CUBE3d", true);
	if(!mlx)
	{
		printf("No se ha creado mlx\n");
		return (EXIT_FAILURE);
	}
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	{
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	//register the key hook
	mlx_key_hook(mlx, &my_keyhook, NULL);
	//register the loop hook
	mlx_loop_hook(mlx, ft_hook, mlx);
	//Start the MiniLibx loop
	mlx_loop(mlx);
	//Terminate and clean
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
/*
*/
