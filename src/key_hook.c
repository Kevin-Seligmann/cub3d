#include "cubed.h"
#include "parser.h"

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	(void)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		//lo que sea
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		//lo que sea
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		//lo que sea
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		//lo que sea
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		//lo que sea
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		//lo que sea
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		//lo que sea
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)	
	if (keydata.key == MLX_KEY_ESCAPE)
    {
        mlx_close_window((mlx_t *)param);
    }
}
