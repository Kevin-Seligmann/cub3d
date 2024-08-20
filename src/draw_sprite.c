/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:18:55 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/20 18:32:38 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	do_sprite_transform(t_dda *dda,
	t_player *player, t_ged *ged, t_sprite *spr)
{
	(void) spr;
	dda->sprite.transform.x = dda->sprite.det_inv * (player->dir.z * \
	dda->sprite.pos.x - player->dir.x * dda->sprite.pos.z);
	dda->sprite.transform.z = dda->sprite.det_inv * (-dda->cam_vect.z * \
	dda->sprite.pos.x + dda->cam_vect.x * dda->sprite.pos.z);
	dda->sprite.screen_x = (int)(ged->img->width / 2 * \
	(1 + dda->sprite.transform.x / dda->sprite.transform.z));
}

static void	get_draw_limits(t_sprite_dda *spr, t_ged *ged)
{
	spr->dim.z = fabs((double)(ged->img->height / spr->transform.z));
	spr->draw_start.z = -spr->dim.z / 2 + ged->img->height / 2;
	if (spr->draw_start.z < 0)
		spr->draw_start.z = 0;
	spr->draw_end.z = spr->dim.z / 2 + ged->img->height / 2;
	if (spr->draw_end.z >= (int)ged->img->height)
		spr->draw_end.z = ged->img->height - 1;
	spr->dim.x = fabs((int)ged->img->height / spr->transform.z);
	spr->draw_start.x = -spr->dim.x / 2 + spr->screen_x;
	if (spr->draw_start.x < 0)
		spr->draw_start.x = 0;
	spr->draw_end.x = spr->dim.x / 2 + spr->screen_x;
	if (spr->draw_end.x >= (int)ged->img->width)
		spr->draw_end.x = ged->img->width - 1;
}

static void	put_sprite_pixel(t_sprite_dda *spr, t_ged *ged)
{
	spr->text.z = ((((spr->ind.z) - ged->img->height / 2 + \
	spr->dim.z / 2) * spr->texture->height) / spr->dim.z);
	spr->text_coord = (spr->texture->width - spr->text.x
			- 1 + spr->text.z * spr->texture->width) * 4;
	spr->color = 0;
	spr->color = get_rgba(spr->texture->pixels[spr->text_coord], \
	spr->texture->pixels[spr->text_coord + 1], \
	spr->texture->pixels[spr->text_coord + 2], \
	spr->texture->pixels[spr->text_coord + 3]);
	if (spr->color != 0)
		mlx_put_pixel(ged->img, ged->img->width
			- spr->ind.x - 1, spr->ind.z, spr->color);
	spr->ind.z ++;
}

static void	sort_sprites(t_sprite_dda *spr, t_player *player)
{
	int			ind;
	int			ind2;
	t_sprite	aux;

	ind = 0;
	while (ind < spr->sprite_count)
	{
		spr->sprites[ind].dist = (player->pos.x - spr->sprites[ind].pos.x) * \
		(player->pos.x - spr->sprites[ind].pos.x) + \
		(player->pos.z - spr->sprites[ind].pos.z) * \
		(player->pos.z - spr->sprites[ind].pos.z);
		ind ++;
	}
	ind = 0;
	while (ind < spr->sprite_count - 1)
	{
		ind2 = ind;
		while (ind2 < spr->sprite_count - 1 - ind)
		{
			if (spr->sprites[ind2].dist < spr->sprites[ind2 + 1].dist)
			{
				aux = spr->sprites[ind2];
				spr->sprites[ind2] = spr->sprites[ind2 + 1];
				spr->sprites[ind2 + 1] = aux;
			}
			ind2++;
		}
		ind ++;
	}
}

static void	draw_sprite(t_ged *ged, t_sprite_dda *spr)
{
	spr->texture = ged->textures.sprites_text[spr->sprite_ind] \
	[ged->textures.sprite_ind[spr->sprite_ind].x];
	spr->ind.x = spr->draw_start.x;
	while (spr->ind.x < spr->draw_end.x)
	{
		if (spr->transform.z > 0 && spr->ind.x > 0 && spr->ind.x < \
		(int) ged->img->width && spr->transform.z < spr->zbuffer[spr->ind.x])
		{
			spr->text.x = (int)((spr->ind.x - (-spr->dim.x / 2 + \
			spr->screen_x)) * spr->texture->width / spr->dim.x);
			spr->ind.z = spr->draw_start.z;
			while (spr->ind.z < spr->draw_end.z)
				put_sprite_pixel(spr, ged);
		}
		spr->ind.x ++;
	}
}

void	draw_sprites(t_cube *data)
{
	int				ind;
	t_sprite		*spr;

	if (data->dda.sprite.sprite_count == 0)
		return ;
	sort_sprites(&data->dda.sprite, &data->sim.player);
	data->dda.sprite.det_inv = 1.0 / (data->dda.cam_vect.x * \
	data->sim.player.dir.z - data->sim.player.dir.x * data->dda.cam_vect.z);
	ind = 0;
	while (ind < data->dda.sprite.sprite_count)
	{
		spr = &data->dda.sprite.sprites[ind];
		data->dda.sprite.sprite_ind = spr->sprite_ind;
		data->dda.sprite.pos.x = spr->pos.x - data->sim.player.pos.x;
		data->dda.sprite.pos.z = spr->pos.z - data->sim.player.pos.z;
		do_sprite_transform(&data->dda, &data->sim.player, &data->ged, spr);
		get_draw_limits(&data->dda.sprite, &data->ged);
		draw_sprite(&data->ged, &data->dda.sprite);
		ind ++;
	}
}
