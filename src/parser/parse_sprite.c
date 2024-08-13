/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:28:56 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/13 02:33:49 by kseligma         ###   ########.fr       */
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
		if (data->parse.sprite_found[ind] && *(data->ged.textures.sprites_text[ind]) == NULL)
			return (true);
		ind ++;
	}
	return (false);
}

bool	is_sprite_id(char *id)
{
	if (!ft_strcmp(SPRITE2_ID, id) || \
	!ft_strcmp(SPRITE3_ID, id) || \
	!ft_strcmp(SPRITE4_ID, id) || \
	!ft_strcmp(SPRITE5_ID, id) || \
	!ft_strcmp(SPRITE6_ID, id) || \
	!ft_strcmp(SPRITE7_ID, id) || \
	!ft_strcmp(SPRITE8_ID, id) || \
	!ft_strcmp(SPRITE9_ID, id))
		return (true);
	return (false);
}

static int	get_sprite_ind(char *id)
{
	if (!ft_strcmp(id, SPRITE2_ID))
		return (0);
	else if (!ft_strcmp(id, SPRITE3_ID))
		return (1);
	else if (!ft_strcmp(id, SPRITE4_ID))
		return (2);
	else if (!ft_strcmp(id, SPRITE5_ID))
		return (3);
	else if (!ft_strcmp(id, SPRITE6_ID))
		return (4);
	else if (!ft_strcmp(id, SPRITE7_ID))
		return (5);
	else if (!ft_strcmp(id, SPRITE8_ID))
		return (6);
	else
		return (7);
}

int	get_sprite_texture(t_cube *data, char **args)
{
	mlx_texture_t	*texture;
	int				sprite_ind;
	int				sprite_frame;

	if (ft_arr_count_arguments(args) != 2)
		return (print_error(-1, WRONG_LINE_CONTENT, 0));
	sprite_ind = get_sprite_ind(args[0]);
	sprite_frame = data->ged.textures.sprite_ind[sprite_ind].z;
	if (sprite_frame == 30)
		return (print_error(0, WAR_TEXTURES_FULL, 0));
	texture = mlx_load_png(args[1]);
	if (!texture)
		return (print_error(-1, CANT_LOAD_TEXTURE, mlx_strerror(mlx_errno)));
	data->ged.textures.sprites_text[sprite_ind][sprite_frame] = texture;
	data->ged.textures.sprite_ind[sprite_ind].z ++;
	return (0);
}
