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
