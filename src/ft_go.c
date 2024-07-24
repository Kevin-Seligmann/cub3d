#include "cubed.h"
#include "parser.h"

int	ft_go(t_cube *game)
{
	mlx_t *mlx;
	(void)game;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "CUBE3d made by KSeligma & OSeivane", true);
	if(!mlx)
		print_error(-1, CANT_MAKE_MLX, 0);
	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("./textures/eagle.png");
	if (!texture)
    {
		print_error(-1, CANT_LOAD_TEXTURE, 0);
		mlx_terminate(mlx);
	}
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
    {
		print_error(-1, CANT_LOAD_IMAGE, 0);
		mlx_terminate(mlx);
	}
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	{
		print_error(-1, CANT_LOAD_IMAGE, 0);
		mlx_terminate(mlx);
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	//Calling raycasting
	ft_raycasting(game);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
