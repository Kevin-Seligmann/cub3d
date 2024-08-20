/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:18:32 by oseivane          #+#    #+#             */
/*   Updated: 2024/08/20 21:41:59 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*Draw the ciruclar miniplayer in Scale proportion of the map,
using less than MM_SCale as multiplier and a colour */
void	draw_mini_player(t_ged *ged, int center_x, int center_z)
{
	double	x;
	double	z;
    double	radius;

	radius = ged->mm_scale / 2.0;
	x = -radius;
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

void	draw_mini_square(t_ged *ged, unsigned int x, unsigned int y, unsigned int colour)
{
	unsigned int	square_x;
	unsigned int	square_y;

	square_x = 0;
	square_y = 0;
	while (square_x < MM_SCALE)
	{
		square_y = 0;
		while (square_y < ged->mm_scale)
		{
			mlx_put_pixel(ged->minimap, x * MM_SCALE + square_x,
				y * MM_SCALE + square_y, colour);
			square_y++;
		}
		square_x++;
	}
}

void	mini_map_corner(t_sim *sim, t_ged *ged, t_v2 *corner, t_v2 *mm_size)
{
	corner->x = sim->player.pos.x - 0.5 * ged->minimap->width / ged->mm_scale;
	corner->z = sim->player.pos.z - 0.5 * ged->minimap->height / ged->mm_scale;
	mm_size->x = ged->minimap->width / ged->mm_scale;
	mm_size->z = ged->minimap->height / ged->mm_scale;
	if (corner->x < 0)
		corner->x = 0;
	else if (corner->x + mm_size->x > (int) sim->width)
		corner->x = sim->width - mm_size->x;
	if (corner->z < 0)
		corner->z = 0;
	else if (corner->z + mm_size->z > (int) sim->height)
		corner->z = sim->height - mm_size->z;
}

void	get_player_center(t_v2 *player_center, t_v2 *corner, t_v2 *mm_size, t_ged *ged, t_sim *sim)
{
	(void) corner;
	(void) mm_size;
	(void) ged;
	player_center->x = ged->minimap->width / 2;
	player_center->z = ged->minimap->height / 2;
	if (corner->x == 0)
		player_center->x = sim->player.pos.x * ged->mm_scale;
	if (corner->z == 0)
		player_center->z = sim->player.pos.z * ged->mm_scale;
	if (corner->x == (int) sim->width - mm_size->x)
		player_center->x = mm_size->x * ged->mm_scale - (sim->width - sim->player.pos.x) * ged->mm_scale;
	if (corner->z == (int) sim->height - mm_size->z)
		player_center->z = mm_size->z * ged->mm_scale - (sim->height - sim->player.pos.z) * ged->mm_scale;
}

/*It draws the minimap in the left upper corner*/
void	draw_mini_map(t_dda *dda, t_ged *ged, t_sim *sim)
{
	int	y;
	int	x;
	t_v2			corner;
	t_v2			mm_size;
	t_v2			player_center;

	(void)dda;
	mini_map_corner(sim, ged, &corner, &mm_size);
	get_player_center(&player_center, &corner, &mm_size, ged, sim);
	y = 0;
	while (y < mm_size.z)
	{
		x = 0;
		while (x < mm_size.x)
		{
			if (corner.z + y >= (int) sim->height || corner.x + x >= (int) sim->width)
				draw_mini_square(ged, x, y, 0);
			else if (sim->map[corner.z + y][corner.x + x] == '1')
				draw_mini_square(ged, x, y, 0xFFFFFFFF);
			else if (sim->map[corner.z + y][corner.x + x] == '0')
				draw_mini_square(ged, x, y, 0xFFFFFFC0);
			else if (sim->map[corner.z + y][corner.x + x] >= 100 && sim->map[corner.z + y][corner.x + x] < 300)
				draw_mini_door(ged, sim, x, y, &corner);
			else if (sim->map[corner.z][corner.x] >= '2' || sim->map[corner.z][corner.x] <= '9') 
				draw_mini_square(ged, x, y, 0x724dbdFF);
			x ++;
		}
		y ++;
	}
	draw_mini_player(ged, player_center.x, player_center.z);
}
