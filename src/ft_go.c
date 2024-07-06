#include "cubed.h"
#include "parser.h"

int	ft_go(t_cube *map)
{
	mlx_t *mlx;
	(void)map;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "CUBE3d made by KSeligma & OSeivane", true);
	if(!mlx)
		print_error(-1, CANT_MAKE_MLX, 0);
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	{
		print_error(-1, CANT_LOAD_IMAGE, 0);
		mlx_terminate(mlx);
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
