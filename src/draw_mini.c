/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:18:32 by oseivane          #+#    #+#             */
/*   Updated: 2024/08/22 19:23:21 by kseligma         ###   ########.fr       */
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

	radius = MIN_WALL_DIST * ged->mm_scale;
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

void	mini_map_corner(t_sim *sim, t_ged *ged, t_vd2 *corner, t_vd2 *center)
{
	corner->x = sim->player.pos.x - 0.5 * ged->minimap->width / ged->mm_scale;
	corner->z = sim->player.pos.z - 0.5 * ged->minimap->height / ged->mm_scale;
	if (corner->x < 0)
		corner->x = 0;
	else if (corner->x + ged->minimap->width / ged->mm_scale > sim->width)
		corner->x = sim->width - ged->minimap->width / ged->mm_scale;
	if (corner->z < 0)
		corner->z = 0;
	else if (corner->z + ged->minimap->height / ged->mm_scale > sim->width)
		corner->z = sim->width - ged->minimap->height / ged->mm_scale;
	center->x = sim->player.pos.x - corner->x;
	center->z = sim->player.pos.z - corner->z;
}

static unsigned int	get_mm_color(t_sim *sim, unsigned int x, unsigned int y)
{
	int		val;

	if (y >= sim->height || x >= sim->width)
		return (0);
	val = sim->map[y][x];
	if (val == '1')
		return(0x000000FF);
	else if (val == '0')
		return(0xFFFFFFC0);
	else if (val >= '2' && val <= '9')
		return(0x724dbdFF);
	else if (val == 100 || val == 200)
		return(0xf71109FF);
	else if (val == 150 || val == 250)
		return(0x08f409FF);
	else if (val > 100 && val < 300)
		return(0xFFD700FF);
	return (0);
}

/*It draws the minimap in the left upper corner*/
void	draw_mini_map(t_ged *ged, \
t_sim *sim, t_minimap *mm)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	color;

	mini_map_corner(sim, ged, &mm->corner, &mm->player_center);
	y=0;
	while (y < ged->minimap->height)
	{
		x = 0;
		while (x < ged->minimap->width)
		{
			color = get_mm_color(sim, mm->corner.x + ((double) x) / (double) (ged->mm_scale), mm->corner.z +  ((double) y) / (double) (ged->mm_scale));
			mlx_put_pixel(ged->minimap, x, y, color);
			x++;
		}
		y++;
	}
	draw_mini_player(ged, mm->player_center.x * ged->mm_scale, mm->player_center.z * ged->mm_scale);
}
