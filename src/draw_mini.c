#include "cubed.h"

/*Draw the ciruclar miniplayer in Scale proportion of the map, using less than MM_SCale as multiplier and a colour */
void	draw_mini_player(t_ged *ged, t_sim *sim)
{
	double	x;
	double	z;
    double	radius;
    double	center_x;
    double	center_z;
	radius = MM_SCALE / 2.0;
	x = -radius;
	center_x = sim->player.pos.x * MM_SCALE + radius;
	center_z = sim->player.pos.z * MM_SCALE + radius;
    while (x <= radius)
    {
		z = -radius;
        while (z <= radius)
        {
            if (x * x + z * z <= radius * radius)
            {
                mlx_put_pixel(ged->minimap, center_x + x, center_z + z, 0xba7e56FF);
            }
		z++;
        }
	x++;
    }		
}

/*Draw the minimap in Scale proportion of the map, using MM_SCale as multiplier  and a colour*/
void	draw_mini_wall(t_ged *ged, unsigned int x, unsigned int y)
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
void	draw_mini_floor(t_ged *ged, unsigned int x, unsigned int y)
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
			mlx_put_pixel(ged->minimap, x * MM_SCALE + square_x, y * MM_SCALE + square_y, 0xFFFFFF);
			square_y++;
		}
		square_x++;
	}
}

void	draw_mini_sprite(t_ged *ged, unsigned int x, unsigned int y)
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
			mlx_put_pixel(ged->minimap, x * MM_SCALE + square_x, y * MM_SCALE + square_y, 0x724dbdFF);
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
				draw_mini_wall(ged, x, y);
			else if (sim->map[y][x] == '0')
				draw_mini_floor(ged, x, y);
			else if (sim->map[y][x] >= 100 && sim->map[y][x] < 300)
				draw_mini_door(ged, sim, x, y);
			else if (sim->map[y][x] >= '2' || sim->map[y][x] <= '9') 
				draw_mini_sprite(ged, x, y);
			x++;
		}
		y++;
	}
}

