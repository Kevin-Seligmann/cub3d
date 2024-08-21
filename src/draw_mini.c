/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:18:32 by oseivane          #+#    #+#             */
/*   Updated: 2024/08/21 17:32:45 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*Draw the ciruclar miniplayer in Scale proportion of the map,
using less than MM_SCale as multiplier and a colour */
void	draw_mini_player(t_ged *ged, double center_x, double center_z)
{
	double	x;
	double	z;
	double	radius;

	radius = ged->mm_scale * 0.5;
	x = -radius;
	while (x <= radius)
	{
		z = -radius;
		while (z <= radius)
		{
			if (x * x + z * z <= radius * radius)
				mlx_put_pixel(ged->minimap, center_x + x, \
				center_z + z, 0xba7e56FF);
			z++;
		}
		x++;
	}
}

void	draw_mini_square(t_ged *ged, unsigned int x, \
unsigned int y, unsigned int colour)
{
	unsigned int	square_x;
	unsigned int	square_y;

	square_x = 0;
	square_y = 0;
	while (square_x < ged->mm_scale)
	{
		square_y = 0;
		while (square_y < ged->mm_scale)
		{
			mlx_put_pixel(ged->minimap, x * ged->mm_scale + square_x,
				y * ged->mm_scale + square_y, colour);
			square_y++;
		}
		square_x++;
	}
}

void	mini_map_corner(t_sim *sim, t_ged *ged, t_v2 *corner, t_vd2 *mm_size)
{
	corner->x = sim->player.pos.x - 0.5 * ged->minimap->width / ged->mm_scale;
	corner->z = sim->player.pos.z - 0.5 * ged->minimap->height / ged->mm_scale;
	mm_size->x = ged->minimap->width / ged->mm_scale;
	mm_size->z = ged->minimap->height / ged->mm_scale;
	if (corner->x + mm_size->x > (int) sim->width)
		corner->x = sim->width - mm_size->x;
	if (corner->x < 0)
		corner->x = 0;
	if (corner->z + mm_size->z > (int) sim->height)
		corner->z = sim->height - mm_size->z;
	if (corner->z < 0)
		corner->z = 0;
}

void	get_player_center(t_minimap *mm, t_ged *ged, t_sim *sim)
{
	(void) ged;
	mm->player_center.x = (sim->player.pos.x - \
	mm->corner.x) * ged->mm_scale;
	mm->player_center.z = (sim->player.pos.z - \
	mm->corner.z) * ged->mm_scale;
	if (mm->corner.x == 0)
		mm->player_center.x = sim->player.pos.x * ged->mm_scale;
	else if (mm->corner.x == (int) sim->width - mm->size.x)
		mm->player_center.x = mm->size.x * ged->mm_scale \
		- (sim->width - sim->player.pos.x) * ged->mm_scale;
	if (mm->corner.z == 0)
		mm->player_center.z = sim->player.pos.z * ged->mm_scale;
	else if (mm->corner.z == (int) sim->height - mm->size.z)
		mm->player_center.z = mm->size.z * ged->mm_scale \
		- (sim->height - sim->player.pos.z) * ged->mm_scale;
}

/*It draws the minimap in the left upper corner*/
void	draw_mini_map(t_ged *ged, \
t_sim *sim, t_minimap *mm)
{
	int		y;
	int		x;

	ft_memset(ged->minimap->pixels, 0, ged->minimap->width \
	* ged->minimap->height * sizeof(int32_t));
	mini_map_corner(sim, ged, &mm->corner, &mm->size);
	get_player_center(mm, ged, sim);
	y = 0;
	while (y < mm->size.z)
	{
		x = 0;
		while (x < mm->size.x)
		{
			draw_square(ged, sim, x, y);
			x ++;
		}
		y ++;
	}
	draw_mini_player(ged, mm->player_center.x, mm->player_center.z);
}
