/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:18:32 by oseivane          #+#    #+#             */
/*   Updated: 2024/08/20 18:23:59 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*Draw the ciruclar miniplayer in Scale proportion of the map,
using less than MM_SCale as multiplier and a colour */
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
				mlx_put_pixel(ged->minimap,
					center_x + x, center_z + z, 0xba7e56FF);
			}
			z++;
		}
		x++;
	}
}

/*Draw the minimap in Scale proportion of the map,
using MM_SCale as multiplier  and a colour*/
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
			mlx_put_pixel(ged->minimap, x * MM_SCALE + square_x,
				y * MM_SCALE + square_y, 0xFFFFFFFF);
			square_y++;
		}
		square_x++;
	}
}

/*Draw the minimap in Scale proportion of the map,
using MM_SCale as multiplier and a colour */
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
			mlx_put_pixel(ged->minimap, x * MM_SCALE + square_x,
				y * MM_SCALE + square_y, 0xFFFFFF);
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
			mlx_put_pixel(ged->minimap, x * MM_SCALE + square_x,
				y * MM_SCALE + square_y, 0x724dbdFF);
			square_y++;
		}
		square_x++;
	}
}

void	mini_map_corner(t_sim *sim, t_ged *ged, t_v2 *corner, t_v2 *mm_size)
{
	corner->x = sim->player.pos.x - 0.5 * ged->minimap->width / MM_SCALE;
	corner->z = sim->player.pos.z - 0.5 * ged->minimap->height / MM_SCALE;
	mm_size->x = ged->minimap->width / MM_SCALE;
	mm_size->z = ged->minimap->height / MM_SCALE;
	if (corner->x > mm_size->x)
		mm_size->x = mm_size->x;
	if (corner->z > mm_size->z)
		mm_size->z =  mm_size->z;
	if (corner->x < 0)
		corner->x = 0;
	if (corner->z < 0)
		corner->z = 0;
}

/*It draws the minimap in the left upper corner*/
void	draw_mini_map(t_dda *dda, t_ged *ged, t_sim *sim)
{
	int				corner_x;
	t_v2			corner;
	t_v2			mm_size;

	(void)dda;
	mini_map_corner(sim, ged, &corner, &mm_size);
	corner_x = corner.x;
	while (corner.z < mm_size.z)
	{
		corner.x = corner_x;
		while (corner.x < mm_size.x)
		{
			draw_mini_player(ged, sim);
			if (sim->map[corner.z - mm_size.z][corner.x - mm_size.x] == '1')
				draw_mini_wall(ged, corner.x - mm_size.x, corner.z - mm_size.z);
			else if (sim->map[corner.z - mm_size.z][corner.x - mm_size.x] == '0')
				draw_mini_floor(ged, corner.x - mm_size.x, corner.z - mm_size.z);
			else if (sim->map[corner.z - mm_size.z][corner.x - mm_size.x] >= 100 && sim->map[corner.z - mm_size.z][corner.x - mm_size.x] < 300)
				draw_mini_door(ged, sim, corner.x - mm_size.x, corner.z);
			else if (sim->map[corner.z - mm_size.z][corner.x - mm_size.x] >= '2' || sim->map[corner.z - mm_size.z][corner.x - mm_size.x] <= '9') 
				draw_mini_sprite(ged, corner.x - mm_size.x, corner.z - mm_size.z);
			corner.x++;
		}
		corner.z++;
	}
}
