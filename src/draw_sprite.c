/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:18:55 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/12 22:23:24 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cubed.h"

static void	do_sprite_transform(t_sprite *spr, t_dda *dda, \
t_player *player, t_ged *ged)
{
	spr->det_inv = 1.0 / (dda->cam_vect.x * \
	player->dir.z - player->dir.x * dda->cam_vect.z);
	spr->transform.x = spr->det_inv * (player->dir.z * \
	spr->pos.x - player->dir.x * spr->pos.z);
	spr->transform.z = spr->det_inv * (- dda->cam_vect.z * \
	spr->pos.x + dda->cam_vect.x * spr->pos.z);
	spr->screen_x = (int) (ged->img->width / 2 * \
	(1 + spr->transform.x / spr->transform.z));
	spr->dim.z = fabs( ((double) (ged->img->height)) / spr->transform.z);	
}

static void	get_draw_limits(t_sprite *spr, t_ged *ged)
{
	spr->draw_start.z = -spr->dim.z / 2 + ged->img->height / 2;
	if (spr->draw_start.z < 0)
		spr->draw_start.z = 0;
	spr->draw_end.z = spr->dim.z  / 2 + ged->img->height / 2;
	if (spr->draw_end.z >= (int) ged->img->height)
		spr->draw_end.z = ged->img->height - 1;
	spr->dim.x = fabs((int) ged->img->height / spr->transform.z);
	spr->draw_start.x = -spr->dim.x / 2 + spr->screen_x;
	if (spr->draw_start.x < 0)
		spr->draw_start.x = 0;
	spr->draw_end.x = spr->dim.x / 2 + spr->screen_x;
	if (spr->draw_end.x >= (int) ged->img->width)
		spr->draw_end.x = ged->img->width - 1;
}

static void	put_sprite_pixel(t_sprite *spr, t_ged *ged)
{
	spr->text.z = ((((spr->ind.z) * 256 - ged->img->height * 128 + \
	spr->dim.z  * 128) * spr->texture->height) / spr->dim.z) / 256;
	spr->text_coord = (spr->text.x + spr->text.z * spr->texture->width) * 4;
	spr->color = get_rgba(spr->texture->pixels[spr->text_coord], \
	spr->texture->pixels[spr->text_coord + 1], \
	spr->texture->pixels[spr->text_coord + 2], \
	spr->texture->pixels[spr->text_coord + 3]);
	if (spr->color != 0)
		mlx_put_pixel(ged->img, spr->ind.x, spr->ind.z, spr->color);
	spr->ind.z ++;
}

static void	draw_sprite(t_ged *ged, t_sprite *spr)
{
	spr->texture = ged->textures.sprites[spr->sprite_ind]\
	[ged->textures.sprite_ind[spr->sprite_ind].x];
	spr->ind.x = spr->draw_start.x;
	while (spr->ind.x < spr->draw_end.x)
	{
		if (!(spr->transform.z > 0 && spr->ind.x > 0 && spr->ind.x < \
		(int) ged->img->width && spr->transform.z < spr->zbuffer[spr->ind.x]))
		{
			spr->ind.x ++;
			continue ;
		}
		spr->zbuffer[spr->ind.x] = spr->transform.z;
		spr->text.x = (int) ((spr->ind.x - (-spr->dim.x / 2 + \
		spr->screen_x)) * spr->texture->width / spr->dim.z);
		spr->ind.z = spr->draw_start.z;
		while (spr->ind.z < spr->draw_end.z)
			put_sprite_pixel(spr, ged);
		spr->ind.x ++;
	}
}

void	draw_sprites(t_cube *data)
{
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
				data->dda.sprite.pos.x = i + 0.5 - data->sim.player.pos.x;
				data->dda.sprite.pos.z = j + 0.5 - data->sim.player.pos.z;
				do_sprite_transform(&data->dda.sprite, \
				&data->dda, &data->sim.player, &data->ged);
				get_draw_limits(&data->dda.sprite, &data->ged);
				draw_sprite(&data->ged, &data->dda.sprite);
			}
			i++;
		}
		j++;
	}
}
