/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:40:16 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/21 16:45:05 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static double	get_sprite_dist(t_player *player, t_sprite_dda *spr, int ind)
{
	return ((player->pos.x - spr->sprites[ind].pos.x) * \
	(player->pos.x - spr->sprites[ind].pos.x) + \
	(player->pos.z - spr->sprites[ind].pos.z) * \
	(player->pos.z - spr->sprites[ind].pos.z));
}

void	sort_sprites(t_sprite_dda *spr, t_player *player)
{
	int			ind;
	int			ind2;
	t_sprite	aux;

	ind = -1;
	while (++ind < spr->sprite_count)
		spr->sprites[ind].dist = get_sprite_dist(player, spr, ind);
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
