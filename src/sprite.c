/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:53:40 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/20 18:33:15 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	update_sprites(t_cube *data)
{
	int				ind;
	t_texture_pack	*textures;

	textures = &data->ged.textures;
	ind = 0;
	while (ind < 8)
	{
		if (textures->sprite_ind[ind].z > 0)
		{
			if (textures->sprite_ind[ind].x == textures->sprite_ind[ind].z - 1)
				textures->sprite_ind[ind].x = 0;
			else
				textures->sprite_ind[ind].x ++;
		}
		ind ++;
	}
}
