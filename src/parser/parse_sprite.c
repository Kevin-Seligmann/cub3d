/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:28:56 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/11 17:35:34 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cubed.h"

/*
	If a sprite has been found on the map, but its texture has not been
	provided
*/
bool	found_sprite_is_not_set(t_cube *data)
{
	int	ind;

	ind = 0;
	while (ind < 8)
	{
		if (data->parse.sprite_found[ind] && data->ged.textures.sprites[ind] == NULL)
			return (true);
		ind ++;
	}
	return (false);
}

/*	else if (is_sprite_id(args[0]))
		return_value = get_sprite_texture(data, args);
*/
