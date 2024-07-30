/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:34:43 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 15:50:14 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

#define todo
/*
	To do:
	Calculate line height based on FOV, HEIGHT and WIDTH to be always squared

	Line height is such that if distance is one block, the wall occupies
	the whole screen.
*/
static void	set_line_limits(t_sim *map)
{
	map->line_height = HEIGHT / map->wall_dist;
	map->line_start = -(int)(map->line_height / 2) + HEIGHT / 2;
	map->line_end = map->line_height / 2 + HEIGHT / 2;
}

/*
	If step is positive, player is moving towards S or E.
	If step is negative, player is moving towards N or W
	If side is 0, ray hit a E or W.
	If side is 1, ray hit N or S.
*/
static void	get_texture(t_sim *map, \
t_texture_pack *textures, mlx_texture_t **texture)
{
	if (map->side == 0 && map->step.x == 1)
		*texture = textures->east_wall;
	else if (map->side == 0 && map->step.x == -1)
		*texture = textures->west_wall;
	else if (map->side == 1 && map->step.z == 1)
		*texture = textures->south_wall;
	else if (map->side == 1 && map->step.z == -1)
		*texture = textures->north_wall;
}

#define todo
/*
	Todo:
	Explain this better
*/
static void	get_texture_x(t_sim *map)
{
	if (map->side == 0)
		map->texture_x = map->player_position.z + \
		map->wall_dist * map->ray_dir.z;
	else
		map->texture_x = map->player_position.x + \
		map->wall_dist * map->ray_dir.x;
	map->texture_x = (map->texture_x - floorf(map->texture_x));
}

/*
	xpos maps '0-1' to 0-texture width
	ypos maps 'line_start - line_end' to '0-texture height'

	MLX makes the pixel array 32 bits per texture, and is
	an array of 8 bits integers. Multiply the coords
	by 4 (If int is 32 bites int).

	Each pixel is an R-G-B-A value, add 0, 1, 2, 3 to get each piece. 
*/
static void	put_texture_pixel(t_sim *map, t_ged *gph, int x, unsigned int y)
{
	mlx_texture_t	*texture;
	int				xpos;
	int				ypos;
	int				tex_coord;

	get_texture(map, &gph->textures, &texture);
	get_texture_x(map);
	xpos = map->texture_x * (float) texture->width;
	ypos = (y - map->line_start) * \
	((texture->height - 1.) / map->line_height);
	tex_coord = (xpos + ypos * texture->width) * 4;
	mlx_put_pixel(gph->img, x, y, \
	get_rgba(texture->pixels[tex_coord], \
	texture->pixels[tex_coord + 1], \
	texture->pixels[tex_coord + 2], \
	texture->pixels[tex_coord + 3]));
}

/*
	Drawing a vertical line based on 3 cases.
	If the pixel is above the texture puts a pixel
	of the ceiling color in the image
	If the pixel is below the texture puts a pixel 
	of the floor color in the image
	If the pixel is inside the texture, maps
	the pixel to the texture
*/
void	draw(t_sim *map, t_ged *gph, t_color *colors, int x)
{
	unsigned int	y;

	set_line_limits(map);
	y = 0;
	while (y < HEIGHT)
	{
		if ((int) y < map->line_start)
			mlx_put_pixel(gph->img, x, y, colors->ceiling_color);
		else if ((int) y >= map->line_end)
			mlx_put_pixel(gph->img, x, y, colors->floor_color);
		else
			put_texture_pixel(map, gph, x, y);
		y ++;
	}
}
