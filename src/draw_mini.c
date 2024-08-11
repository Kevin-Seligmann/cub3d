#include "cubed.h"

/*Draw the miniplayer in Scale proportion of the map, using less than MM_SCale as multiplier and a colour */
void	draw_mini_player(t_ged *ged, t_sim *sim)
{
	double	square_x;
	double	square_z;

	square_x = 0;
	square_z = 0;
	while (square_x < MM_SCALE)
	{
        square_z = 0;
		while (square_z < MM_SCALE)
		{
			mlx_put_pixel(ged->minimap, sim->player.pos.x * MM_SCALE + square_x, sim->player.pos.z * MM_SCALE + square_z, 0xFF0000FF);
			square_z++;
		}
		square_x++;
	}		
			
}

/*Draw the minimap in Scale proportion of the map, using MM_SCale as multiplier  and a colour*/
void	draw_square_1(t_ged *ged, unsigned int x, unsigned int y)
{
	unsigned int	square_x;
	unsigned int	square_y;

	square_x = 0;
	square_y = 0;
	while (square_x < MM_SCALE)
	{
        square_y = 0;
		while (square_y < MM_SCALE)
		{
			mlx_put_pixel(ged->minimap, x * MM_SCALE + square_x, y * MM_SCALE + square_y, 0x0000FF);
			square_y++;
		}
		square_x++;
	}
}

/*Draw the minimap in Scale proportion of the map, using MM_SCale as multiplier and a colour */
void	draw_square_2(t_ged *ged, unsigned int x, unsigned int y)
{
	unsigned int	square_x;
	unsigned int	square_y;

	square_x = 0;
	square_y = 0;
	while (square_x < MM_SCALE)
	{
        square_y = 0;
		while (square_y < MM_SCALE)
		{
			mlx_put_pixel(ged->minimap, x * MM_SCALE + square_x, y * MM_SCALE + square_y, 0xFFFFFFF);
			square_y++;
		}
		square_x++;
	}
}

/*It draws the minimap in the left upper corner*/
void	draw_mini_map(t_dda *dda, t_ged *ged, t_sim *sim)
{
	unsigned int	x;
	unsigned int	y;
	
	(void)dda;

	y = 0;
	while (y < sim->height)
	{
		x = 0;
		while (x < sim->width)
		{
			draw_mini_player(ged, sim);
			if (sim->map[y][x] == '1')
				draw_square_1(ged, x, y);
			else
				draw_square_2(ged, x, y);
			x++;
		}
		y++;
	}
}

