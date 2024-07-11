#include "cubed.h"
#include "parser.h"

void	init_raycasting(t_cube *game)
{
	game->map.player_position.x = 22;
	game->map.player_position.z = 12;
	game->map.player_direction.x = -1;
	game->map.player_direction.z = 0;
	game->map.plane.x = 0;
	game->map.plane.z = 0.66;
	game->map.time = 0;
	game->map.oldtime = 0;
	game->map.mapX = int(game->map.player_position.x);
	game->map.mapZ = int(game->map.player_position.z);
	game->map.deltaDist.x = (game->map.rayDir.x == 0) ? 1e30 : abs(1 / game->map.rayDir.x);
	game->map.deltaDist.z = (game->map.rayDir.z == 0) ? 1e30 : abs(1 / game->map.rayDir.z);
	game->map.hit = 0;
	/*game->map.red = {255, 0, 0};
	game->map.green = {0, 255, 0};
	game->map.blue = {0, 0, 255};
	game-> map.white = {255, 255, 255};
	game->map.yellow = {255, 255, 0};*/
}

void calc_camera(t_cube *game)
{
	while (x < w) //calculate ray postion and direction
	{
		game->map.camera.x = 2 * x / float(w) - 1; //x - coordinate in camera space
		game->map.rayDir.x = game->map.player_direction.x + game->map.plane.x * game->map.camera.x;
		game->map.rayDir.z = game->map.player_direction.z + game->map.plane.x * game->map.camera.x;
		x++;
	}
}

void	calc_step_sideDist(t_cube *game)
{
	if (game->map.rayDir.x < 0)
	{
		game->map.stepX = -1;
		game->map.sideDist.x = (game->map.player_position.x - game->map.mapX) * game->map.deltaDist.x;
	}
	else
	{
		game->map.stepX = -1;
		game->map.sideDist.x = (game->map.mapX + 1.0 - game->map.player_position.x) * game->map.deltaDist.x;
	}
	if
	{
		game->map.stepZ = -1;
		game->map.sideDist.z = (game->map.player_position.z - game->map.mapZ) * game->map.deltaDist.z;
	}
	else
	{
		game->map.stepZ = -1;
		game->map.sideDist.z = (game->map.mapZ + 1.0 - game->map.player_position.z) * game->map.deltaDist.z;
	}
}

void	ft_DDA(t_cube *game)
{
	while (game->map.hit == 0)
	{
		if (game->.map.sideDist.x < game->map.sideDist.z)
		{
			game->map.sideDist.x += game->map.deltaDist.x;
			game->map.mapX += game->map.stepX;
			game->map.side = 0;
		}
		else
		{
			game->map.sideDist.z += game->map.deltaDist.z;
			game->map.mapZ += game->map.stepZ;
			game->map.side = 1;
		}
		if (game->map[game->map.mapX][game->map.mapZ] > 0)
			game->map.hit = 1;
	}
}

void	ft_fisheye(t_cube *game)
{
	if (game->map.side == 0)
		game->map.perpWallDist = (game->map.sideDist.x - game->map.deltaDist.x);
	else
		game->map.perpWallDist = (game->map.sideDist.z - game->map.deltaDist.z);

}

void	calc_draw_fill(t_cube *game)
{
	lineHeight = (int)(h / perpWallDist);
	drawStart = -lineHeight / 2 + h / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + h / 2;
	if (drawEnd >= h)
		drawEnd = h - 1;
}

void	choose_color(t_cube *game)
{

	red = {255, 0, 0};
	green = {0, 255, 0};
	blue = {0, 0, 255};
	white =
}

void	timing_speed(t_cube *game)
{
	game->map.oldTime = game->map.time;
	game->map.time = getTicks(); //equivalencia en lenguaje C.
	game->map.frameTime = (game->map.time - game->map.oldTime) / 1000.0
	//print(1.0 / gme->map.frameTime; printear los frame por segundo
	//redraw(); version en c?
	//cls(); version en c?
	game->map.moveSpeed = game->map.frameTime * 5.0;
	game->map.rotSpeed = game->map.frameTime * 3.0;
}

void	ft_raycasting(t_cube *game)
{
	int	x;

	init_raycasting(game);
	while (!done())
	{
		x = 0;
		while (x < w)
		{
			calc_camera(game);
			calc_step_sideDist(game);
			ft_DDA(game);
			ft_fisheye(game);
			calc_draw_fill(game);
			choose_color(game);
			x++;
		}
		timing_speed(game);
	}
}
