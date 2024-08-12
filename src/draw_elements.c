/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 03:06:39 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/12 15:28:31 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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
			if (sim->map[y][x] == '1')
				mlx_put_pixel(ged->minimap, x, y, 0xFFFF00F0);
			else
				mlx_put_pixel(ged->minimap, x, y, 0x0000FFF0);
			x++;
		}
		y++;
	}
}
static mlx_texture_t	*get_sprite_frame(int sprite_ind, t_ged *ged)
{
	mlx_texture_t	*texture;
	int				frame_ind;

	frame_ind = ged->textures.sprite_ind[sprite_ind].x;
	texture = ged->textures.sprites[sprite_ind][frame_ind];
	if (frame_ind == ged->textures.sprite_ind[sprite_ind].z)
		frame_ind = 0;
	else
		frame_ind ++;
	ged->textures.sprite_ind[sprite_ind].x = frame_ind;
	return (texture);
}

static void	sprite_to_camera_space(t_ged *ged, t_dda *dda, t_player *player, int i, int j, mlx_texture_t *texture)
{
	t_vd2	transform;
	double	inv;
	int		sprite_screen_x;
	int		sprite_height;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		ind_x;
	int		ind_y;
	int		texture_x;
	int		texture_y;
	int		tex_coord;
	unsigned int	color;
	int		d;

	inv = 1.0 / (dda->cam_vect.x * player->dir.x - player->dir.z * dda->cam_vect.z);
	transform.x = inv * (player->dir.z * (i + 0.5) - (player->dir.x * j + 0.5));
	transform.z = inv * (-dda->cam_vect.z * (i + 0.5) + dda->cam_vect.x * (j + 0.5));
	sprite_screen_x = (int) (ged->img->width / 2 * (1 + transform.x / transform.z));
	sprite_height = fabs((int) ged->img->height / transform.z);
	draw_start_y = -sprite_height / 2 + ged->img->height / 2;
	if (draw_start_y < 0)
		draw_start_y = 0;
	draw_end_y = sprite_height / 2 + ged->img->height / 2;
	if (draw_end_y >= (int) ged->img->height)
		draw_end_y = ged->img->height - 1;
	sprite_width = fabs((int) ged->img->height / transform.z);
	draw_start_x = -sprite_width / 2 + sprite_screen_x;
	if (draw_start_x < 0)
		draw_start_x = 0;
	draw_end_x = sprite_width / 2 + sprite_screen_x;
	if (draw_end_x >= (int) ged->img->width)
		draw_end_x = ged->img->width - 1;
	ind_x = draw_start_x;
	while (ind_x < draw_end_x)
	{
		if (!(transform.z > 0 && ind_x > 0 && ind_x < (int) ged->img->width && transform.z < dda->zbuffer[ind_x]))
		{
			ind_x ++;
			continue ;
		}
		dda->zbuffer[ind_x] = transform.z;
		texture_x = (int) ((ind_x - (-sprite_width / 2 + sprite_screen_x)) * texture->width / sprite_width);
		while (ind_y < draw_end_y)
		{
			d = ind_y * 256 - ged->img->height * 128 + sprite_height * 128;
			texture_y = (int) (((d * (int) texture->height) / sprite_height) / 256);
			tex_coord = (texture->width * texture_y + texture_x) * 4;
			color = get_rgba(texture->pixels[tex_coord], \
			texture->pixels[tex_coord + 1], \
			texture->pixels[tex_coord + 2], \
			texture->pixels[tex_coord + 3]);
			(void) texture_y;
			(void) texture_x;
			(void) color;
			if (color == 0xFFFFFFFF || color == 0x00FFFFFFFF)
			{
				ind_y ++;
				continue;
			}
//			mlx_put_pixel(ged->img, dda->x, dda->y, color);
			ind_y ++;
		}
		ind_x ++;
	}
}

void	draw_sprites(t_cube *data)
{
	mlx_texture_t	*texture;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j < data->sim.height)
	{
		i = 0;
		while (i < data->sim.width)
		{
			if (data->sim.map[j][i] > '1' && data->sim.map[j][i] < '9' + 1)
			{
				texture = get_sprite_frame(data->sim.map[j][i] - 2 - '0', &data->ged);
				sprite_to_camera_space(&data->ged, &data->dda, &data->sim.player, i, j, texture);
			}
			i++;
		}
		j++;
	}
}
