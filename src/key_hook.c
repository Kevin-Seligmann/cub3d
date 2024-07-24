#include "cubed.h"
#include "parser.h"

void ft_hook(void *param)
{
	mlx_t *mlx;
	t_cube *game;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE) || mlx_is_key_down(mlx, MLX_KEY_X))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
      if(game->map.map[int(game->map.player_position.x + game->map.player_direction.x * game->map.moveSpeed)][int(game->map.player_position.z)] == false)
    	  game->map.player_position.x += game->map.player_direction.x * game->map.moveSpeed;
      if(game->map[int(game->map.player_position.x)][int(game->map.player_position.z + game->map.player_direction.z * game->map.moveSpeed)] == false)
	  	  game->map.player_position.z += game->map.player_direction.z * game->map.moveSpeed;
    }
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
      if(game->map[int(game->map.player_position.x - game->map.player_direction.x * game->map.moveSpeed)][int(game->map.player_position.z)] == false)
        game->map.player_position.x -= game->map.player_direction.x * game->map.moveSpeed;
      if(game->map[int(game->map.player_position.x)][int(game->map.player_position.z - game->map.player_direction.z * game->map.moveSpeed)] == false)
        game->map.player_position.z -= game->map.player_direction.z * game->map.moveSpeed;
    }
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
    
  }
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
     
  }
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
      //both camera direction and camera plane must be rotated
      game->map.oldDir.x = game->map.player_direction.x;
      game->map.player_direction.x = game->map.player_direction.x * cos(game->map.rotSpeed) - game->map.player_direction.z * sin(game->map.rotSpeed);
      game->map.player_direction.z = game->map.oldDir.x * sin(game->map.rotSpeed) + game->map.player_direction.z * cos(game->map.rotSpeed);
      game->map.oldPlane.x = game->map.plane.x;
      game->map.plane.x = game->map.plane.x * cos(game->map.rotSpeed) - game->map.plane.z * sin(game->map.rotSpeed);
      game->map.plane.z = game->map.oldPlane.x * sin(game->map.rotSpeed) + game->map.plane.z * cos(game->map.rotSpeed);
    }
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
      //both camera direction and camera plane must be rotated
      game->map.oldDir.x = game->map.player_direction.x;
      game->map.player_direction.x = game->map.player_direction.x * cos(-game->map.rotSpeed) - game->map.player_direction.z * sin(-game->map.rotSpeed);
      game->map.player_direction.z = game->map.oldDir.x * sin(-game->map.rotSpeed) + game->map.player_direction.z * cos(-game->map.rotSpeed);
      game->map.oldPlane.x = game->map.plane.x;
      game->map.plane.x = game->map.plane.x * cos(-game->map.rotSpeed) - game->map.plane.z * sin(-game->map.rotSpeed);
      game->map.plane.z = game->map.oldPlane.x * sin(-game->map.rotSpeed) + game->map.plane.z * cos(-game->map.rotSpeed);
    }
}
