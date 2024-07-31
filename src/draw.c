/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:34:43 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/31 10:37:44 by kseligma         ###   ########.fr       */
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
static void	set_line_limits(t_dda *dda)
{
	dda->line_height = HEIGHT / dda->wall_dist;
	dda->line_start = -(int)(dda->line_height / 2) + HEIGHT / 2;
	dda->line_end = dda->line_height / 2 + HEIGHT / 2;
}

/*
	If step is positive, player is moving towards S or E.
	If step is negative, player is moving towards N or W
	If side is 0, ray hit a E or W.
	If side is 1, ray hit N or S.
*/
static void	get_texture(t_dda *dda, \
t_texture_pack *textures, mlx_texture_t **texture)
{
	if (dda->side == 0 && dda->step.x == 1)
		*texture = textures->east_wall;
	else if (dda->side == 0 && dda->step.x == -1)
		*texture = textures->west_wall;
	else if (dda->side == 1 && dda->step.z == 1)
		*texture = textures->south_wall;
	else if (dda->side == 1 && dda->step.z == -1)
		*texture = textures->north_wall;
}

#define todo
/*
	Todo:
	Explain this better
*/
static void	get_texture_x(t_dda *dda, t_player *player)
{
	if (dda->side == 0)
		dda->texture_x = player->pos.z + dda->wall_dist * dda->ray_dir.z;
	else
		dda->texture_x = player->pos.x + dda->wall_dist * dda->ray_dir.x;
	dda->texture_x = (dda->texture_x - floorf(dda->texture_x));
}

/*
	xpos maps '0-1' to 0-texture width
	ypos maps 'line_start - line_end' to '0-texture height'

	MLX makes the pixel array 32 bits per texture, and is
	an array of 8 bits integers. Multiply the coords
	by 4 (If int is 32 bites int).

	Each pixel is an R-G-B-A value, add 0, 1, 2, 3 to get each piece. 
*/
static void	put_texture_pixel(t_dda *dda, t_ged *gph, int x, unsigned int y)
{
	mlx_texture_t	*texture;
	int				xpos;
	int				ypos;
	int				tex_coord;

	get_texture(dda, &gph->textures, &texture);
	xpos = dda->texture_x * (float) texture->width;
	ypos = (y - dda->line_start) * \
	((texture->height - 1.) / dda->line_height);
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
void	draw(t_dda *dda, t_ged *ged, t_sim *sim, int x)
{
	unsigned int	y;

	set_line_limits(dda);
	y = 0;
	while (y < HEIGHT)
	{
		if ((int) y < dda->line_start)
			mlx_put_pixel(ged->img, x, y, sim->ceiling_color);
		else if ((int) y >= dda->line_end)
			mlx_put_pixel(ged->img, x, y, sim->floor_color);
		else
		{
			get_texture_x(dda, &sim->player);
			put_texture_pixel(dda, ged, x, y);
		}
		y ++;
	}
}
