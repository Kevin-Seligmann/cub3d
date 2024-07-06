#include "cubed.h"
#include "parser.h"

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE) || mlx_is_key_down(mlx, MLX_KEY_X))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		//image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		//image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		//image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		//image->instances[0].x += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		//image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		//image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		//image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		//image->instances[0].x += 5;
	}
}

int	ft_go(t_cube *map)
{
	mlx_t *mlx;
	(void)map;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "CUBE3d made by KSeligma & OSeivane", true);
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
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
/*
*/
